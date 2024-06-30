/*
 * keypad.h
 *
 *  Created on: Jun 30, 2024
 *      Author: xcite
 */

#ifndef INC_KEYPAD_H_
#define INC_KEYPAD_H_



/*---------------- INCLUDES -------------------*/
#include "../../GPIO/inc/stm32f103c6_gpio.h"
// Include the GPIO hardware abstraction layer


/*---------------- MACROS --------------------*/
#define ECU_KEYPAD_ROW 4
#define ECU_KEYPAD_COL 4

/*---------------- DATA TYPES -----------------*/
/**
 * @struct Keypad_t
 * @brief Structure to store the configuration of a keypad.
 */
typedef struct {
    GPIO_PinConfig_t Pin;
    GPIO_TypeDef *GPIOx;
}Keypad_PinCfg_t;
typedef struct {
    Keypad_PinCfg_t keypad_row_pins[ECU_KEYPAD_ROW]; /**< Array of pin configurations for keypad rows. */
    Keypad_PinCfg_t keypad_col_pins[ECU_KEYPAD_COL]; /**< Array of pin configurations for keypad columns. */
} Keypad_t;

/*------------ FUNCTION DECLARATIONS ----------*/
/**
 * @brief Initializes the keypad.
 * @param keypad Pointer to a Keypad_t structure containing the keypad configuration.
 * @return Standard return type indicating success or failure.
 */
void ECU_keypad_initialize( Keypad_t *keypad);

/**
 * @brief Retrieves the value from the keypad.
 * @param keypad Pointer to a Keypad_t structure containing the keypad configuration.
 * @param value Reference parameter to store the retrieved value.
 * @return Standard return type indicating success or failure.
 */
uint8_t ECU_keypad_get_value( Keypad_t *keypad);


#endif /* INC_KEYPAD_H_ */
