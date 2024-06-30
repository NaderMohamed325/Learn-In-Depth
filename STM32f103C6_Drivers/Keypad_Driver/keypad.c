/*
 * keypad.c
 *
 *  Created on: Jun 30, 2024
 *      Author: xcite
 */
#include "inc/keypad.h"

const static uint8_t btn_values[ECU_KEYPAD_ROW][ECU_KEYPAD_COL] =
{
    {'7', '8', '9', '/'},
    {'4', '5', '6', '*'},
    {'1', '2', '3', '-'},
    {'#', '0', '=', '+'}
};

/**
 * @brief Initializes the keypad.
 * @param keypad Pointer to a Keypad_t structure containing the keypad configuration.
 * @return Standard return type indicating success or failure.
 */
void ECU_keypad_initialize(Keypad_t *keypad)
{
    // Check if the keypad pointer is valid
    if (keypad == NULL) {
        return;
    }

    // Initialize each row pin of the keypad
    for (int i = 0; i < ECU_KEYPAD_ROW; i++)
    {
        MCAL_GPIO_Init(keypad->keypad_row_pins[i].GPIOx, &(keypad->keypad_row_pins[i].Pin));
    }

    // Initialize each column pin of the keypad
    for (int i = 0; i < ECU_KEYPAD_COL; i++)
    {
        MCAL_GPIO_Init(keypad->keypad_col_pins[i].GPIOx, &(keypad->keypad_col_pins[i].Pin));
    }
}

/**
 * @brief Retrieves the value from the keypad.
 * @param keypad Pointer to a Keypad_t structure containing the keypad configuration.
 * @param value Reference parameter to store the retrieved value.
 * @return The retrieved value from the keypad or 0 if no button is pressed.
 */
uint8_t ECU_keypad_get_value(Keypad_t *keypad)
{

    for (int i = 0; i < ECU_KEYPAD_ROW; i++)
    {
        uint8_t value_pin;

        // Set all rows to GPIO_LOW
        for (int j = 0; j < ECU_KEYPAD_ROW; j++)
        {
            MCAL_GPIO_WritePin(keypad->keypad_row_pins[j].GPIOx, keypad->keypad_row_pins[j].Pin.GPIO_PinNumber, GPIO_PIN_RESET);
        }

        // Set the current row to GPIO_HIGH
        MCAL_GPIO_WritePin(keypad->keypad_row_pins[i].GPIOx, keypad->keypad_row_pins[i].Pin.GPIO_PinNumber, GPIO_PIN_SET);
        delay(30);  // Adjust this delay based on your requirements

        // Read the columns
        for (int j = 0; j < ECU_KEYPAD_COL; j++)
        {
            value_pin = MCAL_GPIO_ReadPin(keypad->keypad_col_pins[j].GPIOx, keypad->keypad_col_pins[j].Pin.GPIO_PinNumber);

            // Check if the button is pressed (GPIO_HIGH)
            if (value_pin == GPIO_PIN_SET)
            {
                return btn_values[i][j];
            }
        }
    }
    return -1;  // Return 0 if no button is pressed
}
