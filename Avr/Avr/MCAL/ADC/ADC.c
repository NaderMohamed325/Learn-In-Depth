/*
 * ADC.c
 *
 * Created: 7/21/2024 1:34:21 PM
 *  Author: xcite
 */
#include "ADC.h"

/**
 * @brief Initializes the ADC with the given parameters.
 *
 * @param adc Pointer to the ADC_t structure containing the initialization parameters.
 */
void ADC_Init(ADC_t *adc) {
    ADC_Disable();
    
    // Set voltage reference
    if (!adc->Voltage_ref) {
        ADMUX &= ~(0b11 << 6);
    } else {
        ADMUX |= adc->Voltage_ref;
    }
    
    // Set the ADC channel
    ADMUX |= adc->Channel;
    
    // Set the prescaler
    ADCSRA |= adc->Prescaller_Adc;
    
    // Set the auto trigger source
    SFIOR |= adc->Trigger_Source;
    
    // Enable or disable ADC interrupt
    if (adc->Interrupt_Status) {
        ADC_Interrupt_Enable();
    } else {
        ADC_Interrupt_Disable();
    }
    
    ADC_Enable();
}

/**
 * @brief Reads the ADC conversion result for the selected channel.
 *
 * @param adc Pointer to the ADC_t structure containing the ADC configuration.
 * @return The 10-bit ADC conversion result.
 */
uint16_t Adc_Read_Result(ADC_t *adc) {
    // Start the ADC conversion
    ADC_Start();
    
    // Wait for the conversion to complete
    while (!(ADCSRA & (1 << 4)));
    
    // Clear the ADC conversion complete flag
    ACD_Flag_Clear();
    
    // Read and return the ADC result
    return ADC;
}
