#ifndef TIMER_H_
#define TIMER_H_


#include <stdbool.h>
#include "../gpio/gpio.h"
// Timer modes
#define Normal_Mode 0x00
#define PWM_Phase_Correct 0x40
#define CTC 0x08
#define F_PWM 0x48

// Output Compare Pin Modes
#define OC0_Off 0x00
#define OC0_Toggle 0x10
#define OC0_Clear 0x20
#define OC0_Set 0x30

// Prescalers
#define No_Prescaler 0x01
#define Prescaler_8 0x02
#define Prescaler_64 0x03
#define Prescaler_256 0x04
#define Prescaler_1024 0x05

// Interrupt Status
#define Disable 0x00
#define OverFlow_Interrupt 0x01
#define Compare_Interrupt 0x02
#define OverCompare_Interrupt 0x03

// Timer structure
typedef struct {
	uint8_t Timer_Mode;
	uint8_t Output_Pin_Functionality;
	uint8_t Prescaler;
	uint8_t Compare_Value;
	uint8_t Force_Output_Pin;
	uint8_t interrupt_status;
	void (*Call_Back_Overflow)(void);
	void (*Call_Back_Compare)(void);
} Timer0_t;

// Function prototypes
uint8_t Timer_TCNT0_Get_value(void);
void Timer_OCR0_Set_Compare_Value(uint8_t value);
bool Timer0_Init(Timer0_t *timer);
void Timer0_PWM_Init(uint8_t duty_cycle, uint8_t output_mode, uint8_t prescaler);

#endif /* TIMER_H_ */
