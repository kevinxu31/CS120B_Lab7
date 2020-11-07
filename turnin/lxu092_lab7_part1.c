/*	Author: lab
 *  Partner(s) Name: Luofeng Xu
 *	Lab Section:022
 *	Assignment: Lab 7  Exercise 1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *	Demo Link: Youtube URL>https://youtu.be/ygEW_5pI2bw
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned short low;
unsigned char high;


void ADC_init(){
	ADCSRA |=(1<<ADEN)|(1<<ADSC)|(1<<ADATE);
}




int main(void) {
	DDRA=0x00;PORTA=0xFF;
	DDRB=0xFF;PORTB=0x00;
	DDRD=0xFF;PORTC=0x00;
	ADC_init();
	while (1) {
		unsigned short x=ADC;
		low=(char)x;
		high=(char)(x>>8);
		PORTB=low;
		PORTD=high;
	}
	return 1;
}
