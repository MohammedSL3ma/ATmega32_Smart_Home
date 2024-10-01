/*
 * Smart_home_LCD.c
 *
 * Created: 9/20/2024 7:37:47 PM
 * Author : Mohamed 
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "Kypd.h"
#include "user_defined.h"


int main(void) {
	CLCD_init();
	Kypad_init();
	
	user members[3] = {
		{"mohamed", '5', '6'},
		{"kareem", '7', '8'},
		{"ali", '9', '3'}
	};
	
	room rooms[2] = {
		{0, 0, 0, 1},  // fan_pin is 0 and light_pin is 1 for room 1
		{0, 0, 2, 3}   // fan_pin is 2 and light_pin is 3 for room 2
	};
	
	U8 input = '\0';
	int current_user = -1;
	
	// Set pin directions
	for (int i = 0; i < 2; i++) {
		DIO_enumSetPinDirection(rooms[i].fan_pin, DIO_PORTA, DIO_OUTPUT);
		DIO_enumSetPinDirection(rooms[i].light_pin, DIO_PORTA, DIO_OUTPUT);
	}
	
	while (1) {
		if (current_user == -1) {
			CLCD_CLR();
			CLCD_SendString("enter id");
			
			do {
				input = Kypad_GetKey();
			} while (input == 'f');
			
			for (int i = 0; i < 3; i++) {
				if (members[i].id == input) {
					for (int attempt = 0; attempt < 3; attempt++) {
						CLCD_CLR();
						CLCD_SendString("enter pass");
						
						do {
							input = Kypad_GetKey();
						} while (input == 'f');
						
						if (input == members[i].passkey) {
							current_user = i;
							break;
							} else if (attempt == 2) {
							CLCD_CLR();
							CLCD_SendString("system closed");
							return 0;
						}
					}
					break;
				}
			}
		}
		
		if (current_user != -1) {
			CLCD_CLR();
			CLCD_SendString("welcome ");
			CLCD_SendString(members[current_user].name);
			_delay_ms(1000);
			
			while (1) {
				CLCD_CLR();
				CLCD_SendString("room  1");
				CLCD_GoTo(2, 1);
				CLCD_SendString("room  2");
				
				do {
					input = Kypad_GetKey();
				} while (input == 'f' || (input != '1' && input != '2'));
				
				int k = (input - '0') - 1;
				CLCD_CLR();
				CLCD_SendString("1 fan");
				CLCD_GoTo(2, 1);
				CLCD_SendString("2 light");
				
				do {
					input = Kypad_GetKey();
				} while (input == 'f' || (input != '1' && input != '2'));
				
				if (input == '1') {
					CLCD_CLR();
					CLCD_SendString("1 fan off");
					CLCD_GoTo(2, 1);
					CLCD_SendString("2 fan on");
					
					do {
						input = Kypad_GetKey();
					} while (input == 'f' || (input != '1' && input != '2'));
					
					rooms[k].fan = (input == '2') ? 1 : 0;
					DIO_enumSetPinValue(rooms[k].fan_pin, DIO_PORTA, rooms[k].fan);
					} else if (input == '2') {
					CLCD_CLR();
					CLCD_SendString("1 light off");
					CLCD_GoTo(2, 1);
					CLCD_SendString("2 light on");
					
					do {
						input = Kypad_GetKey();
					} while (input == 'f' || (input != '1' && input != '2'));
					
					rooms[k].light = (input == '2') ? 1 : 0;
					DIO_enumSetPinValue(rooms[k].light_pin, DIO_PORTA, rooms[k].light);
				}
				
				CLCD_CLR();
				CLCD_SendString("1 sign out");
				CLCD_GoTo(2, 1);
				CLCD_SendString("2 keep signed");
				
				do {
					input = Kypad_GetKey();
				} while (input == 'f' || (input != '1' && input != '2'));
				
				if (input == '1') {
					current_user = -1;
					break;  // Go back to login
				}
				// If input is '2', the loop continues, keeping the user signed in
			}
		}
	}
	return 0;
}

