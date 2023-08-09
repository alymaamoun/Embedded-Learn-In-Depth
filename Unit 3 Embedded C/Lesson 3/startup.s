/*Startup file for CortexM3*/
/* @copyrigths for embeddedsystems_uc*/


/*SRAM 0x20000000*/







/**********************************************************************
************************VECTORTABLE START******************************
**********************************************************************/

.section .vectors /*This command is given to the linker script to put the following lines in a section called .vectors*/

/*The processor will power on address 0x80000000*/
.word 0x20001000  /*At this address the processor will find the address 0x20001000*/
				  /*This address will be assigned to the SP*/	
				  /*.word will put 32bit with the value assigned*/
				  /*stack is assigned to be 1K*/
.word _reset					/*1  Reset*/
.word _Vector_handler			/*2  NMI  */
.word _Vector_handler			/*3  HardFault  */
.word _Vector_handler			/*4  MemManageFault  */
.word _Vector_handler			/*5  BusFault  */
.word _Vector_handler			/*6  UsageFault  */
.word _Vector_handler			/*7  RESERVED  */
.word _Vector_handler			/*8  RESERVED  */
.word _Vector_handler			/*9  RESERVED  */
.word _Vector_handler			/*10 RESERVED  */
.word _Vector_handler			/*11 SVCall  */
.word _Vector_handler			/*12 DebugMoniter  */
.word _Vector_handler			/*13 RESERVED  */
.word _Vector_handler			/*14 PendSV  */
.word _Vector_handler			/*15 SysTick  */
.word _Vector_handler			/*16 IRQ0  */
.word _Vector_handler			/*17 IRQ1  */
.word _Vector_handler			/*18 IRQ2  */
.word _Vector_handler			/*19 IRQ3  */
					/*To be continued till IRQ67*/

/**********************************************************************
*************************VECTORTABLE END*******************************
**********************************************************************/






/**********************************************************************
*************************SECTIONS START********************************
**********************************************************************/
/*reset section will branch on main function and after exiting from main it will branch on itself at line 16*/

.section .text /*This command is given to the linker script to put the following lines in a section called .text*/

_reset:
	bl main
	b .

/*This command is passed to enable the 32-16 switching*/
.thumb_func

_Vector_handler:
	b _reset


/**********************************************************************
*************************SECTIONS END**********************************
**********************************************************************/