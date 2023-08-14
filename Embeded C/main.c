/*
 * main.c
 *
 *  Created on: 14 Dec 2022
 *      Author: kareem
 */
#include "STD_TYPES.h"
#include "Macros.h"
#include <util/delay.h>
#include "Dio.h"
#include "timer1_interface.h"
int main()
{
    Dio_SetPinMode(DIO_PORTA,DIO_PIN0,DIO_PIN_INPUT_PULLUP);
    Dio_SetPinMode(DIO_PORTD,DIO_PIN5,DIO_PIN_OUTPUT);
    Dio_SetPinMode(DIO_PORTD,DIO_PIN4,DIO_PIN_OUTPUT);
    TIMER1_voidSetTopValue(20000);
    TIMER1A_voidSetComperMatchValue(1000);//Base motor
    TIMER1B_voidSetComperMatchValue(700);//Arm motor
    TIMER1_voidInit();
    while(1)
    {
        while(STD_HIGH == Dio_ReadPinLevel(DIO_PORTA,DIO_PIN0));//polling untill pus button


        TIMER1A_voidSetComperMatchValue(1000);//Base motor
        TIMER1B_voidSetComperMatchValue(2500);//Arm motor
        _delay_ms(2000);
        TIMER1B_voidSetComperMatchValue(700);//Arm motor
        _delay_ms(2000);
        TIMER1A_voidSetComperMatchValue(1500);//Base motor
        _delay_ms(2000);
        TIMER1B_voidSetComperMatchValue(2500);//Arm motor
        _delay_ms(2000);
        TIMER1B_voidSetComperMatchValue(700);//Arm motor
        _delay_ms(2000);
        TIMER1A_voidSetComperMatchValue(1000);//Base motor
        _delay_ms(2000);
    }
}
    /*
    u8 read='0';
    Dio_SetPinMode(DIO_PORTA,DIO_PIN0,DIO_PIN_INPUT_PULLUP);
    Dio_SetPinMode(DIO_PORTD,DIO_PIN5,DIO_PIN_OUTPUT);
    Dio_SetPinMode(DIO_PORTD,DIO_PIN4,DIO_PIN_OUTPUT);
    //pin rx input
    Dio_SetPinMode(DIO_PORTD,DIO_PIN0,DIO_PIN_INPUT_FLOATING);
    //pin Tx output
    Dio_SetPinMode(DIO_PORTD,DIO_PIN1,DIO_PIN_OUTPUT);
    TIMER1_voidSetTopValue(20000);
    TIMER1A_voidSetComperMatchValue(1000);//Base
    TIMER1B_voidSetComperMatchValue(700);//end efector
    USART_voidInit();
    TIMER1_voidInit();
    
    while (1)
    {
        while (STD_HIGH == Dio_ReadPinLevel(DIO_PORTA,DIO_PIN0));//polling untill pus button
        if('0'==read)
        {
            TIMER1A_voidSetComperMatchValue(1000);//position_1
            _delay_ms(500);
            //swab افرد الدراع
            USART_voidSendData('0');//0
            read = USART_u8Receive();//1
            if ('1'==read)
            {
                TIMER1B_voidSetComperMatchValue(2000);//end efector
                _delay_ms(2000);
                TIMER1B_voidSetComperMatchValue(700);//end efector
                //لم الدراع 
                USART_voidSendData('1');//1
                read = USART_u8Receive();//2
            }
        }
        if ('2' == read)
        {
           TIMER1A_voidSetComperMatchValue(2000);//position_2
            _delay_ms(500);
            //افرد الدراع
            USART_voidSendData('2');//2
            read = USART_u8Receive();//3
            if (3==read)
            {
                TIMER1B_voidSetComperMatchValue(2000);//end efector
                _delay_ms(2000);
                TIMER1B_voidSetComperMatchValue(700);//end efector
                //لم الدراع
                USART_voidSendData('3');//3
                read = USART_u8Receive();//4
            }
        }
        if ('4'==read)
        {
            read = '0';
        } 
    }
    */
