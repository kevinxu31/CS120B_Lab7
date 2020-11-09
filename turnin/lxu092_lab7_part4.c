/*	Author: lab
 *  Partner(s) Name: Luofeng Xu
 *	Lab Section:022
 *	Assignment: Lab 7  Exercise 4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *	Demo Link: Youtube URL>https://youtu.be/W5Q226b22lc
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned char b;
void ADC_init(){
	ADCSRA |=(1<<ADEN)|(1<<ADSC)|(1<<ADATE);
}




int main(void) {
	DDRA=0x00;PORTA=0xFF;
	DDRB=0xFF;PORTB=0x00;
	ADC_init();
	while (1) {

		unsigned short x=ADC;
		if (x<56){
			b=0x00;
		}
		else if(x>=56&&x<121){
			b=0x01;
		}
		else if(x>=121&&x<186){
                        b=0x03;
                }
		else if(x>=186&&x<251){
                        b=0x07;
                }
		else if(x>=251&&x<316){
                        b=0x0F;
                }
		else if(x>=316&&x<381){
                        b=0x1F;
                }
		else if(x>=381&&x<446){
                        b=0x3F;
                }
		else if(x>=446&&x<511){
                        b=0x7F;
                }
		else if(x>=511){
			b=0xFF;
		}
	PORTB=b;

	}
	return 1;
}
