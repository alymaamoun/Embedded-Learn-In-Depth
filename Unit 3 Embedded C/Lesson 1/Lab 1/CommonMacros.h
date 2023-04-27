/*****************************************************************
 * File Name: CommonMacros.h
 *
 * Author   : Aly Maamoun
 *
 * File Description: Common macros
 *
 * Date: 4/27/2023
 *****************************************************************/


#ifndef COMMONMACROS_H_
#define COMMONMACROS_H_


#define ShiftLeft(m) (m=1<<m)
#define ShiftRight(m) (m=1>>m)
#define SET_BIT(Reg,m) (Reg|=1<<m)
#define CLEAR_BIT(Reg,m) (Reg&=(~1<<m))
#define TOGGLE_BIT(Reg,m) (Reg^=(1<<m))

#define CLEAR_BYTE(Reg,m) (Reg&=~(0xF<<m))
#define SET_BYTE(Reg,m) (Reg|=(F<<m))

#endif /* COMMONMACROS_H_ */
