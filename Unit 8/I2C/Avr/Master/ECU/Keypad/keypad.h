/*
 * keypad.h
 *
 * Created: 7/4/2024 8:46:14 PM
 *  Author: xcite
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "../../MCAL/gpio/gpio.h"

/*---------------- MACROS --------------------*/
#define ECU_KEYPAD_ROW 4
#define ECU_KEYPAD_COL 4

/*---------------- DATA TYPES -----------------*/
/**
 * @struct Keypad_t
 * @brief Structure to store the configuration of a keypad.
 */
typedef struct {
    Pin_config_t keypad_row_pins[ECU_KEYPAD_ROW]; /**< Array of pin configurations for keypad rows. */
    Pin_config_t keypad_col_pins[ECU_KEYPAD_COL]; /**< Array of pin configurations for keypad columns. */
} Keypad_t;

/*------------ FUNCTION DECLARATIONS ----------*/
/**
 * @brief Initializes the keypad.
 * @param keypad Pointer to a Keypad_t structure containing the keypad configuration.
 * @return Standard return type indicating success or failure.
 */
void keypad_initialize( Keypad_t *keypad);

/**
 * @brief Retrieves the value from the keypad.
 * @param keypad Pointer to a Keypad_t structure containing the keypad configuration.
 * @param value Reference parameter to store the retrieved value.
 * @return Standard return type indicating success or failure.
 */
void keypad_get_value( Keypad_t *keypad,  unsigned char *value);



#endif /* KEYPAD_H_ */