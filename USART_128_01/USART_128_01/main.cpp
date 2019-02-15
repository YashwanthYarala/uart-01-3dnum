/*
 * USART_128_01.cpp
 *
 * Created: 1/29/2019 10:51:39 PM
 * Author : user
 */ 

#include <avr/io.h>
#define BAUD 9600
#define F_CPU 8000000UL
#define BAUDRATE ((F_CPU)/16*BAUD))-1
void uart_init();
void uart_tx(unsigned char data);

void uart_init()
{
	
	UBRR0H=(BAUDRATE>>8);
	UBRR0L=BAUDRATE;
	UCSR0B|=(1<<TXEN0)|(1<<RXEN0);
	UCSR0C|=(1<<UCSZ00)|(1<<UCSZ01);
}

void uart_tx( unsigned char data)
{
	while(!((UCSR0A)|(1<<UDRE0)));
	UDR0 = data;
	
}


int main(void)
{ 
	uart_init();
    /* Replace with your application code */
    while (1) 
    {
	uart_tx('a');
	uart_tx('b');
	
    }
}


