/*
 * spi_attiny45.c
 *
 * Created: 8/18/2017 01:00:22 AM
 *  Author: Hasib
 */ 


#include <avr/io.h>
#include<util/delay.h>

// Initialize SPI Master Device (without interrupt)
void spi_init_master (void)
{
	// Set MOSI, SCK as Output
	DDRB = (1<<5)|(1<<3);
	
	// Enable SPI, Set as Master
	//Prescaler: Fosc/16, Enable Interrupts
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}
// Initialize SPI Slave Device
void spi_init_slave (void)
{
	DDRB = (1<<6);     //MISO as OUTPUT
	SPCR = (1<<SPE);   //Enable SPI
}
//Function to send and receive data for both master and slave
unsigned char spi_tranceiver (unsigned char data)
{
	// Load data into the buffer
	SPDR = data;
	
	//Wait until transmission complete
	while(!(SPSR & (1<<SPIF) ));
	
	// Return received data
	return(SPDR);
}

int main(void)
{
	DDRB |=(1<<PINB0);
	PORTB |=(1<<PINB0);
	spi_init_master();
	spi_init_slave();
	spi_tranceiver(0b11111111);
    while(1)
    {
		
        //TODO:: Please write your application code 
    }
}