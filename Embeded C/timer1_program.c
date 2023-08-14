/*
 * timer1_program.c
 *
 *  Created on: 18 Nov 2022
 *      Author: kareem
 */
#include "STD_TYPES.h"
#include "Macros.h"
#include "Timer1_interface.h"
#include "Timer1_register.h"
#include "Timer1_confg.h"
#include "Timer1_privet.h"

#define ICU_RISING_EDGE 1
#define ICU_FALLNG_EDGE 2
void TIMER1_voidInit(void)
{
    //Chosse Fast PWM mode and Top is ICR1
    CLR_BIT(TCCR1A,TCCR1A_WGM10);
    SET_BIT(TCCR1A,TCCR1A_WGM11);
    SET_BIT(TCCR1B,TCCR1B_WGM12);
    SET_BIT(TCCR1B,TCCR1B_WGM13);

    //Claer at CTC and set at TOP
    CLR_BIT(TCCR1A,TCCR1A_COM1A0);
    SET_BIT(TCCR1A,TCCR1A_COM1A1);
    CLR_BIT(TCCR1A,TCCR1A_COM1B0);
    SET_BIT(TCCR1A,TCCR1A_COM1B1);

    //Chosse Prescaller to divide by 8
    CLR_BIT(TCCR1B,TCCR1B_CS10);
    SET_BIT(TCCR1B,TCCR1B_CS11);
    CLR_BIT(TCCR1B,TCCR1B_CS12);
    
    //Disablr all of Interrupts
    CLR_BIT(TIMSK,TIMSK_TICIE1);
    CLR_BIT(TIMSK,TIMSK_TOIE1);
    CLR_BIT(TIMSK,TIMSK_OCIE1A);
    CLR_BIT(TIMSK,TIMSK_OCIE1B);
   
}

void TIMER1_voidSetTopValue(u16 copy_u16TopValue)
{
    ICR1 = copy_u16TopValue;
}
void TIMER1A_voidSetComperMatchValue(u16 copy_u16CompValue)
{
    OCR1A = copy_u16CompValue;
}

void TIMER1B_voidSetComperMatchValue(u16 copy_u16CompValue)
{
    OCR1B = copy_u16CompValue;
}

void ICU_voidInit(void)
{
    SET_BIT(TCCR1B,TCCR1B_ICNC1);
    SET_BIT(TCCR1B,TCCR1B_ICES1);
    SET_BIT(TIMSK,TIMSK_TICIE1);
}

u8 ICU_voidEdgeSelect(u8 Copy_u8Edge)
{
    u8 Local_u8ErrorStatus = OK;
    switch (Copy_u8Edge)
    {
    case ICU_RISING_EDGE:
        SET_BIT(TCCR1B,TCCR1B_ICES1);
        break;
    case ICU_FALLNG_EDGE:
        CLR_BIT(TCCR1B,TCCR1B_ICES1);
        break;
    
    default:
        Local_u8ErrorStatus = NOT_OK;
        break;
    }
    return Local_u8ErrorStatus;
}

u16 ICU_u16InputCaptureRead(void)
{
    return ICR1;
}
void ICU_voidInturreptEnable(void)
{
    SET_BIT(TIMSK,TIMSK_TICIE1);
}
void ICU_voidInturreptDisable(void)
{
    CLR_BIT(TIMSK,TIMSK_TICIE1);
}
