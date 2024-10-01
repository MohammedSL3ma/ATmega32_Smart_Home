/*
 * Small_project.c
 *
 * Created: 9/18/2024 8:38:54 PM===================yjh=2022
 * Author : mido
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "USART_interface.h"
#include "Kypd.h"
U8 i=0;
U8 id1=1;
U8 id2=2;
U8 p1=1;
U8 p2=2;
U8 id=0;
U8 p=0;
U8 room=0;
U8 device=0;
U8 action =0;

U8 get_choise(void);

int main ()
{
	Kypad_init();
	USART_voidINIT();
		
	DIO_enumSetPortDirection(DIO_PORTB,255);
	DIO_enumSetPortValue(DIO_PORTB,0);
	
	DIO_enumSetPinDirection(DIO_PIN0,DIO_PORTD,DIO_INPUT);
	DIO_enumSetPinDirection(DIO_PIN1,DIO_PORTD,DIO_OUTPUT);
	USART_VoidSendString("\r\n******************************\r\n");
	USART_VoidSendString("Welcome! \r\n");
	_delay_ms(1000);
	USART_VoidSendString("Enter Your ID: ");
	id=get_choise();
     USART_voidTRANSMITR(id+48);
		
	if(id!=id1&&id!=id2)
	{
		USART_VoidSendString("System Closed");
	}
	else{

	while(i<3)
	{
		i++;
		USART_VoidSendString("\r\nEnter Password: ");
		p=get_choise();
		USART_VoidSendString("*\r\n ");
		if(!((id==id1&&p==p1)||(id==id2&&p==p2)))
		{
		USART_VoidSendString("\r\nTry : ");
		USART_voidTRANSMITR(48+4-i);
		}
		USART_VoidSendString("\r\n******************************\r\n");
	
		if((id==id1&&p==p1)||(id==id2&&p==p2))
		{
			while(1)
			{
				USART_VoidSendString("\r\n******************************\r\n");
				
				/*********************************ROOM****************************/

				USART_VoidSendString(" 1 : ROOM 1\r\n");
				USART_VoidSendString(" 2 : ROOM 2\r\n");
				/*********************************ROOM****************************/
				room=get_choise();
		
			    /*********************************device****************************/

			     USART_VoidSendString(" 1 : LED \r\n");
			     USART_VoidSendString(" 2 : FAN\r\n");
			    /*********************************device****************************/
				device=get_choise();
			    /*********************************Action****************************/

			    USART_VoidSendString(" 1 : ON \r\n");
			    USART_VoidSendString(" 2 : OFF\r\n");
			    /*********************************Action****************************/
				action=get_choise();
				
				switch(room)
				{
					/***********************************ROOM1*************************/
					case 1:
					{
						if (device==1&&action==1)
						{
							DIO_enumSetPinValue(DIO_PIN1,DIO_PORTB,DIO_HIGH);
						}
						else if (device==2&&action==1)
						{
							DIO_enumSetPinValue(DIO_PIN0,DIO_PORTB,DIO_HIGH);
						}
						else if (device==1&&action==2)
						{
							DIO_enumSetPinValue(DIO_PIN1,DIO_PORTB,DIO_LOW);
						}
						else
						{
							DIO_enumSetPinValue(DIO_PIN0,DIO_PORTB,DIO_LOW);
						}
						
						
					}break;
					/***********************************ROOM2*************************/
					case 2:
					{
						if (device==1&&action==1)
						{
							DIO_enumSetPinValue(DIO_PIN2,DIO_PORTB,DIO_HIGH);
						}
						else if (device==2&&action==1)
						{
							DIO_enumSetPinValue(DIO_PIN3,DIO_PORTB,DIO_HIGH);
						}
						else if (device==1&&action==2)
						{
							DIO_enumSetPinValue(DIO_PIN2,DIO_PORTB,DIO_LOW);
						}
						else
						{
							DIO_enumSetPinValue(DIO_PIN3,DIO_PORTB,DIO_LOW);
						}
					}break;
			}
			

			
		}
	   }
	}
			
		}
		
		USART_VoidSendString("\r\n System Closed !!");	
	}
	





/***********************************************************************************************/

U8 get_choise(void)
{   
	U8 choise='f';
	  do
	  {
		  choise=Kypad_GetKey();
	  }	while(choise=='f');
	return choise;
}
/**********************************************************************************************/

