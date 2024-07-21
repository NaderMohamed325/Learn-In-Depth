#include "Timer.h"

// Global pointer to Timer0_t for ISR use
Timer0_t *global_timer = NULL;

/**
* @brief Get the current value of the Timer/Counter0 register (TCNT0).
*
* This function returns the current count value of Timer/Counter0.
*
* @return Current value of the TCNT0 register.
*/
uint8_t Timer_TCNT0_Get_value(void) {
	return TCNT0;
}

/**
* @brief Set the compare value for Timer/Counter0 Output Compare Register (OCR0).
*
* This function sets the value of the OCR0 register, which is used to generate
* a compare match interrupt or to set the output pin behavior.
*
* @param value The compare value to be set in the OCR0 register.
*/
void Timer_OCR0_Set_Compare_Value(uint8_t value) {
	OCR0 = value;
}

/**
* @brief Initialize Timer0 with the given configuration.
*
* This function initializes Timer0 with the settings provided in the
* Timer0_t structure. It configures the timer mode, output pin functionality,
* prescaler, and compare value.
*
* @param timer Pointer to the Timer0_t structure containing the configuration.
* @return true if initialization is successful, false otherwise.
*/
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
		// Clear bits 4 and 5 for OC0 Off
		TCCR0 &= ~(3 << 4);
		} else {
		// Set Output Pin Functionality
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
	TCCR0 |= timer->Precaller;

	// Enable global interrupts
	sei();

	return true;
}

/**
* @brief Initialize Timer0 for PWM generation.
*
* This function initializes Timer0 to generate a PWM signal with the specified
* duty cycle, output mode, and prescaler.
*
* @param duty_cycle The duty cycle of the PWM signal (0-255).
* @param output_mode The output mode for the PWM signal (OC0_Clear or OC0_Set).
* @param prescaler The prescaler value for the timer.
*/
void Timer0_PWM_Init(uint8_t duty_cycle, T_OC0Pin_t output_mode, T_clk_t prescaler) {
	Timer0_t timer = {
		.Timer_Mode = F_PWM, // Fast PWM mode
		.Output_Pin_Functionality = output_mode,
		.Precaller = prescaler,
		.Compare_Value = duty_cycle,
		.Force_Output_Pin = Disable,
		.interrupt_status = interrupt_Disable,
		.Call_Back_Overflow = NULL,
		.Call_Back_Compare = NULL
	};

	Timer0_Init(&timer);
}

// ISR for Timer0 Overflow
ISR(TIMER0_OVF_vect) {
	if (global_timer->Call_Back_Overflow != NULL) {
		global_timer->Call_Back_Overflow();
	}
}

// ISR for Timer0 Compare Match
ISR(TIMER0_COMP_vect) {
	if (global_timer->Call_Back_Compare != NULL) {
		global_timer->Call_Back_Compare();
	}
}
