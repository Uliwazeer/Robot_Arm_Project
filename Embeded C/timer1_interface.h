/*
 * timer1_interface.h
 *
 *  Created on: 18 Nov 2022
 *      Author: kareem
 */

#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

void TIMER1_voidInit(void);

void TIMER1_voidSetTopValue(u16 copy_u16TopValue);

void TIMER1A_voidSetComperMatchValue(u16 copy_u16CompValue);
void TIMER1B_voidSetComperMatchValue(u16 copy_u16CompValue);

/*ICU part*/
void ICU_voidInit(void);

u8 ICU_voidEdgeSelect(u8 Copy_u8Edge);

u16 ICU_u16InputCaptureRead(void);
void ICU_voidInturreptEnable(void);
void ICU_voidInturreptDisable(void);


#endif /* TIMER1_INTERFACE_H_ */
