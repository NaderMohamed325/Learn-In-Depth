
#include "Timer.h"

// Global pointer to Timer0_t for ISR use
Timer0_t *global_timer = NULL;

uint8_t Timer_TCNT0_Get_value(void) {
	return TCNT0;
}

void Timer_OCR0_Set_Compare_Value(uint8_t value) {
	OCR0 = value;
}

bool Timer0_Init(Timer0_t *timer) {
	if (!timer) {
		return false;
	}

	global_timer = timer;

	// Reset TCCR0 register
	TCCR0 = 0x00;

	// Set Timer mode
	TCCR0 |= timer->Timer_Mode;

	// Configure Output Pin Functionality
	if (timer->Output_Pin_Functionality == OC0_Off) {
		TCCR0 &= ~(3 << 4);
		} else {
		TCCR0 |= timer->Output_Pin_Functionality;
	}

	// Set Compare Value
	Timer_OCR0_Set_Compare_Value(timer->Compare_Value);

	// Force Output Compare Pin
	if (timer->Force_Output_Pin) {
		TCCR0 |= (1 << FOC0);
	}

	// Enable interrupts in TIMSK
	TIMSK &= ~(1 << TOIE0) & ~(1 << OCIE0); // Disable both interrupts initially
	if (timer->interrupt_status == OverFlow_Interrupt) {
		TIMSK |= (1 << TOIE0); // Enable Overflow Interrupt
		} else if (timer->interrupt_status == Compare_Interrupt) {
		TIMSK |= (1 << OCIE0); // Enable Compare Match Interrupt
		} else if (timer->interrupt_status == OverCompare_Interrupt) {
		TIMSK |= (1 << TOIE0) | (1 << OCIE0); // Enable both interrupts
	}

	// Set Prescaler
	TCCR0 |= timer->Prescaler;

	// Enable global interrupts
	sei();

	return true;
}

void Timer0_PWM_Init(uint8_t duty_cycle, uint8_t output_mode, uint8_t prescaler) {
	Timer0_t timer = {
		.Timer_Mode = F_PWM, // Fast PWM mode
		.Output_Pin_Functionality = output_mode,
		.Prescaler = prescaler,
		.Compare_Value = duty_cycle,
		.Force_Output_Pin = Disable,
		.interrupt_status = Disable,
		.Call_Back_Overflow = NULL,
		.Call_Back_Compare = NULL
	};

	Timer0_Init(&timer);
}

ISR(TIMER0_OVF_vect) {
	if (global_timer->Call_Back_Overflow != NULL) {
		global_timer->Call_Back_Overflow();
	}
}

ISR(TIMER0_COMP_vect) {
	if (global_timer->Call_Back_Compare != NULL) {
		global_timer->Call_Back_Compare();
	}
}
/*
Timer0_PWM_Init(46, OC0_Clear, Prescaler_256);
Timer0_PWM_Init(30, OC0_Clear, Prescaler_256);
*/