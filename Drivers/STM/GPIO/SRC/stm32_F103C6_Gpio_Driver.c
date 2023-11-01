#include "Stm32_F103C6_Gpio_Driver.h"





volatile GPIO_TypeDef* GPIO_INSTANT[5]={GPIOA,GPIOB,GPIOC,GPIOD,GPIOE};//array to carry the addresses of the base addresses of each gpio instant


GPIO_PinConfig_t GPIO_Configuration[ConfiguredPins]=
{
		{.GPIO_PortNumber=GPIO_PORT_A,.GPIO_PinNumber=GPIO_PIN_1,.GPIO_Direction=GPIO_PORT_INPUT,.GPIO_Resistance=GPIO_RESISTANCE_FLOATING},
		{.GPIO_PortNumber=GPIO_PORT_A,.GPIO_PinNumber=GPIO_PIN_7,.GPIO_Direction=GPIO_PORT_INPUT,.GPIO_Resistance=GPIO_RESISTANCE_FLOATING},
		{.GPIO_PortNumber=GPIO_PORT_B,.GPIO_PinNumber=GPIO_PIN_1,.GPIO_Direction=GPIO_PORT_OUTPUT,.GPIO_ALTERNATE=GPIO_ALTERNATE_DIO,.GPIO_OutputMode=GPIO_OUTPUTMODE_PUSH_PULL,.GPIO_Output_Speed=GPIO_SPEED_10M},
		{.GPIO_PortNumber=GPIO_PORT_B,.GPIO_PinNumber=GPIO_PIN_7,.GPIO_Direction=GPIO_PORT_OUTPUT,.GPIO_ALTERNATE=GPIO_ALTERNATE_DIO,.GPIO_OutputMode=GPIO_OUTPUTMODE_PUSH_PULL,.GPIO_Output_Speed=GPIO_SPEED_10M}
};


/**================================================================
 * @Fn			-MCAL_GPIO_InitAll
 * @brief 		-Initialize GPIO Modules according to the container
 * @param [in] 	-Container: array of pins to be configured
 *
 * @retval 		-E ok or E not ok
 * Note			-the package contains instant A,B,C,D,E ;
 *				 however no external pin is connected to port E
 */
uint8_t MCAL_GPIO_InitAll(GPIO_PinConfig_t *Container)
{
	uint8_t instances=0;
	for(;instances<ConfiguredPins;instances++)
	{
		uint8_t status=MCAL_GPIO_Init(&(Container[instances]));
		if(status)
		{

		}
		else
		{
			return E_NOT_OK;
		}
	}
	return E_OK;
}



uint8_t MCAL_GPIO_Init_ValidateInput(GPIO_PinConfig_t* PinConfig)
{
	if((PinConfig->GPIO_ALTERNATE!=GPIO_ALTERNATE_DIO)||(PinConfig->GPIO_ALTERNATE!=GPIO_ALTERNATE_ALT)||(PinConfig->GPIO_ALTERNATE!=GPIO_ALTERNATE_ADC))
	{
		return E_NOT_OK;
	}
	if(PinConfig->GPIO_Direction>1)
	{
		return E_NOT_OK;
	}
	if((PinConfig->GPIO_OutputMode!=GPIO_OUTPUTMODE_PUSH_PULL)||(PinConfig->GPIO_OutputMode!=GPIO_OUTPUTMODE_OPEN_DRAIN))
	{
		return E_NOT_OK;
	}
	if((PinConfig->GPIO_Output_Speed!=GPIO_SPEED_10M)||(PinConfig->GPIO_Output_Speed!=GPIO_SPEED_2M)||(PinConfig->GPIO_Output_Speed!=GPIO_SPEED_50M))
	{
		return E_NOT_OK;
	}
	if(PinConfig->GPIO_PinNumber>15)
	{
		return E_NOT_OK;
	}
	if(PinConfig->GPIO_PortNumber>4)
	{
		return E_NOT_OK;
	}
	if((PinConfig->GPIO_Resistance!=GPIO_RESISTANCE_FLOATING)||(PinConfig->GPIO_Resistance!=GPIO_RESISTANCE_PULLDOWN)||(PinConfig->GPIO_Resistance!=GPIO_RESISTANCE_PULLUP))
	{
		return E_NOT_OK;
	}
	return E_OK;
}


/**================================================================
 * @Fn			-MCAL_GPIO_Init
 * @brief 		-Initialize GPIOx PINy according to the specified
 * 				 parameter in the PinConfig
 * @param [in] 	-GPIOx: where x can be (A..E depending on device used)
 * @param [in] 	-PinConfig: pointer to a GPIO_PinConfig_t that contains
 * 				 the settings
 *
 * @retval 		-none
 * Note			-the package contains instant A,B,C,D,E ;
 *				 however no external pin is connected to port E
 */
uint8_t MCAL_GPIO_Init(GPIO_PinConfig_t* PinConfig)
{
#if SAFE_MODE==1
	uint8_t status= MCAL_GPIO_Init_ValidateInput(PinConfig);
	if(statues==E_NOT_OK){return E_NOT_OK;}
#endif
	GPIO_INSTANT[PinConfig->GPIO_PortNumber]->CRL_Plus_CRH.ALL&=~(uint64_t)((uint64_t)(0xf)<<((uint64_t)(PinConfig->GPIO_PinNumber)*4));//Clear the MOD,CNF of the bit
	if(PinConfig->GPIO_Direction==GPIO_PORT_OUTPUT)//if output
	{	//select output mode , output speed, check the alt func
		GPIO_INSTANT[PinConfig->GPIO_PortNumber]->CRL_Plus_CRH.ALL|=((uint64_t)((uint64_t)(PinConfig->GPIO_OutputMode|PinConfig->GPIO_ALTERNATE|PinConfig->GPIO_Output_Speed))<<(uint64_t)((PinConfig->GPIO_PinNumber)*4));
	}
	else	//set resistance, and direction , used registers: CRx[CNF] , no modifications on MOD as it's already cleared, and ODR for the resistance
	{
		GPIO_INSTANT[PinConfig->GPIO_PortNumber]->CRL_Plus_CRH.ALL|=(PinConfig->GPIO_Resistance==GPIO_RESISTANCE_FLOATING)?((uint64_t)GPIO_RESISTANCE_FLOATING<<((uint64_t)(PinConfig->GPIO_PinNumber)*4)):((uint64_t)0b10<<(uint64_t)((uint64_t)(PinConfig->GPIO_PinNumber)*4));// don't check on ADC as CNF already cleared to zero which is the mode of ADC
		GPIO_INSTANT[PinConfig->GPIO_PortNumber]->ODR.All=(PinConfig->GPIO_Resistance==GPIO_RESISTANCE_PULLDOWN)?(GPIO_INSTANT[PinConfig->GPIO_PortNumber]->ODR.All)&(uint64_t)(~(uint64_t)0b1<<PinConfig->GPIO_PinNumber):1;//if pull up or pull down
	}
	return E_OK;
}

/**================================================================
 * @Fn			-MCAL_GPIO_DeInit
 * @brief 		-DeInitialize GPIOx PINy according to the specified
 * 				 parameter in the PinConfig
 * @param [in] 	-GPIOx: where x can be (A..E depending on device used)
 * @retval 		-none
 * Note			-
 */
void MCAL_GPIO_DeInit(uint8_t Port)
{
	GPIO_INSTANT[Port]->CRL_Plus_CRH.ALL=0x4444444444444444;
	GPIO_INSTANT[Port]->ODR.All=	0x00000000;
	GPIO_INSTANT[Port]->BSRR.All=0x00000000;
	GPIO_INSTANT[Port]->BRR.All=0x00000000;
	GPIO_INSTANT[Port]->LCKR.All=0x00000000;
	//GPIOx->IDR=(read only);
}


/**================================================================
 * @Fn			-MCAL_GPIO_ReadPin
 * @brief 		-Read specific pin
 * @param [in] 	-GPIOx: where x can be (A..E depending on device used)
 * @param [in] 	-PinNumber: pin number to be read according to @ref GPIO_PINS_define
 * @retval 		-the input pin value (two values based on @ref GPIO_PINS_define
 * Note			-
 */
uint8_t MCAL_GPIO_ReadPin(uint8_t Port,uint16_t Pin)
{return (((GPIO_INSTANT[Port]->IDR.All)&(1<<Pin))!=GPIO_PIN_STATE_RESET)?GPIO_PIN_STATE_SET:GPIO_PIN_STATE_RESET;}
/**================================================================
 * @Fn			-MCAL_GPIO_ReadPort
 * @brief 		-Read port
 * @param [in] 	-GPIOx: where x can be (A..E depending on device used)
 * @retval 		-the input port value
 * Note			-
 */
uint16_t MCAL_GPIO_ReadPort(uint8_t Port)
{return (uint16_t)GPIO_INSTANT[Port]->IDR.All;}
/**================================================================
 * @Fn			-MCAL_GPIO_WritePin
 * @brief 		-write on specific pin
 * @param [in] 	-GPIOx: where x can be (A..E depending on device used)
 * @param [in] 	-PinNumber: pin number to be read according to @ref GPIO_PINS_define
 * @param [in]   -Value: the output pin value (two values based on @ref GPIO_PINS_define
 * @retval 		-None
 * Note			-
 */
void MCAL_GPIO_WritePin(uint8_t Port,uint16_t Pin,uint8_t Value)
{(Value!=GPIO_PIN_STATE_RESET)?((GPIO_INSTANT[Port]->ODR.All)|=GPIO_PIN_STATE_SET<<Pin):((GPIO_INSTANT[Port]->ODR.All)&=~(GPIO_PIN_STATE_SET<<Pin));}
/**================================================================
 * @Fn			-MCAL_GPIO_WritePort
 * @brief 		-write on specific port
 * @param [in] 	-GPIOx: where x can be (A..E depending on device used)
 * @param [in]   -Value: the output pin value
 * @retval 		-None
 * Note			-
 */
void MCAL_GPIO_WritePort(uint8_t Port,uint16_t Value)
{(GPIO_INSTANT[Port]->ODR.All)=Value;}
/**================================================================
 * @Fn			-MCAL_GPIO_TogglePin
 * @brief 		-toggle  specific pin
 * @param [in] 	-GPIOx: where x can be (A..E depending on device used)
 * @param [in] 	-PinNumber: pin number to be read according to @ref GPIO_PINS_define
 * @retval 		-None
 * Note			-
 */
void MCAL_GPIO_TogglePin(uint8_t Port,uint16_t Pin)
{GPIO_INSTANT[Port]->ODR.All^=1<<Pin;}
/**================================================================
 * @Fn			-MCAL_GPIO_TogglePin
 * @brief 		-toggle specific port
 * @param [in] 	-GPIOx: where x can be (A..E depending on device used)
 * @retval 		-None
 * Note			-
 */
void MCAL_GPIO_TogglePort(uint8_t Port)
{(GPIO_INSTANT[Port]->ODR.All)=~(GPIO_INSTANT[Port]->ODR.All);}
/**================================================================
 * @Fn			-MCAL_GPIO_LockPin
 * @brief 		-Lock specific port
 * @param [in] 	-GPIOx: where x can be (A..E depending on device used)
 * @param [in] 	-PinNumber: pin number to be read according to @ref GPIO_PINS_define
 * @retval 		-return ok or not ok depending or @ref GPIO_LOCK_RETURN_define
 * Note			-
 */
uint8_t MCAL_GPIO_LockPin(uint8_t Port,uint16_t PinNumber)
{
	volatile uint32_t temp=1<<16;//set LCKK
	temp|=GPIO_PIN_STATE_SET<<PinNumber;//set the pin number
	GPIO_INSTANT[Port]->LCKR.All=temp; //write 1 LCKK and choose the pin
	GPIO_INSTANT[Port]->LCKR.All=GPIO_PIN_STATE_SET<<PinNumber;//write 0 LCKK by writing the pin number shifted
	GPIO_INSTANT[Port]->LCKR.All=temp; //write 1 LCKK by assigning with the pin number and LCKK again
	temp=GPIO_INSTANT[Port]->LCKR.All; //first read (0)
	if((GPIO_INSTANT[Port]->LCKR.All)&1<<16)//(must be 1)
	{
		return GPIO_LOCK_RETURN_ENABLED;
	}
	else
	{
		return GPIO_LOCK_RETURN_ERROR;
	}
}



