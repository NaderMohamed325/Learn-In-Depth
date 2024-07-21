/*
 * ADC.h
 *
 * Created: 7/21/2024 1:34:07 PM
 *  Author: xcite
 */

#ifndef ADC_H_
#define ADC_H_

#include "../gpio/gpio.h"

// Voltage Reference Selections
typedef enum {
    AREF_Internal_Off = 0,
    ACC_Cap_AREF = (0b01 << 6),
    Internal_26_Cap_AREF = (0b11 << 6),
} Voltage_Ref_t;

// ADC Channel Mux Selections
typedef enum {
    ADC0 = 0,
    ADC1,
    ADC2,
    ADC3,
    ADC4,
    ADC5,
    ADC6,
    ADC7
} ADC_Channel_Mux_t;

#define ADC_Enable()                (ADCSRA |= (1 << 7))
#define ADC_Disable()               (ADCSRA &= ~(1 << 7))

#define ADC_Start()                 (ADCSRA |= (1 << 6))
#define ADC_Stop()                  (ADCSRA &= ~(1 << 6))

#define ADC_Auto_Trigger_On()       (ADCSRA |= (1 << 5))
#define ADC_Auto_Trigger_Off()      (ADCSRA &= ~(1 << 5))

#define ADC_Interrupt_Enable()      (ADCSRA |= (1 << 3))
#define ADC_Interrupt_Disable()     (ADCSRA &= ~(1 << 3))

#define ACD_Flag_Clear()            (ADCSRA |= (1 << 4))

// ADC Prescaler Selections
#define ADC_PRESCALER_2    0x01
#define ADC_PRESCALER_4    0x02
#define ADC_PRESCALER_8    0x03
#define ADC_PRESCALER_16   0x04
#define ADC_PRESCALER_32   0x05
#define ADC_PRESCALER_64   0x06
#define ADC_PRESCALER_128  0x07

// ADC Auto Trigger Source Selections
typedef enum {
    ADC_FREE_RUNNING       = 0b000,  // Free Running mode
    ADC_ANALOG_COMPARATOR  = 0b001,  // Analog Comparator
    ADC_EXTERNAL_INTERRUPT = 0b010,  // External Interrupt Request 0
    ADC_TIMER0_COMPARE     = 0b011,  // Timer/Counter0 Compare Match
    ADC_TIMER0_OVERFLOW    = 0b100,  // Timer/Counter0 Overflow
    ADC_TIMER1_COMPARE_B   = 0b101,  // Timer/Counter1 Compare Match B
    ADC_TIMER1_OVERFLOW    = 0b110,  // Timer/Counter1 Overflow
    ADC_TIMER1_CAPTURE     = 0b111   // Timer/Counter1 Capture Event
} ADC_AutoTriggerSource;

// ADC configuration structure
typedef struct {
    Voltage_Ref_t Voltage_ref;
    ADC_Channel_Mux_t Channel;
    uint8_t Prescaller_Adc;
    ADC_AutoTriggerSource Trigger_Source;
    uint8_t Interrupt_Status;
} ADC_t;

void ADC_Init(ADC_t *adc);
uint16_t Adc_Read_Result(ADC_t *adc);

#endif /* ADC_H_ */
