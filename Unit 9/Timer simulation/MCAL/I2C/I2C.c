#include "I2C.h"

#define prescaler 1 //1 4 16 64

#define F_CPU 8000000UL


void MCAL_I2C_Init(unsigned long SCL_Clock){
	TWBR=(unsigned char) (((F_CPU/SCL_Clock)-16)/(2*prescaler));
	if (prescaler == 0)
	TWSR=0;
	
	else if (prescaler == 4)
	TWSR=1;
	
	else if (prescaler == 16)
	TWSR=2;
	
	else if (prescaler == 64)
	TWSR=3;
}
void MCAL_I2C_Start(void){
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while (((TWCR &(1<<7))==0));                 // wait to finish
	while ((TWSR)!=0x08);                   //Start Condition has Been Transmitted
}
void MCAL_I2C_Write(uint8_t Byte){
	TWDR = Byte;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while ((TWCR & 0x80)==0);               //wait to finish
}
void MCAL_I2C_Stop(void){
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}