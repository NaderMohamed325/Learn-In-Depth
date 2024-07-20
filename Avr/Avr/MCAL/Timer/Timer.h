#ifndef TIMER_H_
#define TIMER_H_

#include "../gpio/gpio.h"
#include <stdbool.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#define Enable  1
#define Disable 0

typedef enum {
	Normal = 0x00,
	PWM = 0x40,
	CTC = 0x08,
	F_PWM = 0x48,
} T_modes_t;

typedef enum {
	OC0_Off = 0, // clear
	OC0_Toggle = (1 << 4),
	OC0_Clear = (1 << 5),
	OC0_Set = (3 << 4),
} T_OC0Pin_t;

typedef enum {
	No_clock = 0,
	Prescaller_1,
	Prescaller_8,
	Prescaller_64,
	Prescaller_256,
	Prescaller_1024,
	EX_Falling,
	EX_Rising,
} T_clk_t;

#define interrupt_Disable     0
#define OverFlow_Interrupt    1
#define Compare_Interrupt     2
#define OverCompare_Interrupt 3

typedef struct {
	uint8_t Timer_Mode;
	uint8_t Output_Pin_Functionality;
	uint8_t Precaller;
	uint8_t Compare_Value;
	uint8_t Force_Output_Pin;
	uint8_t interrupt_status;
	void (*Call_Back_Overflow)(void);
	void (*Call_Back_Compare)(void);
} Timer0_t;

bool Timer0_Init(Timer0_t *timer);
uint8_t Timer_TCNT0_Get_value(void);
void Timer_OCR0_Set_Compare_Value(uint8_t value);

#endif /* TIMER_H_ */
