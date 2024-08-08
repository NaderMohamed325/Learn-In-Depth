/*
* gpio.h
*
* Created: 6/28/2024 6:13:21 PM
*  Author: Nader
*/

#ifndef GPIO_H_
#define GPIO_H_
#define F_CPU 8000000UL
#include "Memory_Map.h"
#include "Utils.h"
#include <avr/interrupt.h>
#include <stdlib.h>
#include <stdio.h>
#include <util/delay.h>

#define A 0
#define B 1
#define C 2
#define D 3

void delay_ms(unsigned int ms);

/**
 * @brief Standard return type for functions.
 */
typedef enum {
    ROK, /**< Return OK */
    NOK  /**< Return Not OK */
} Std_return;

/**
 * @brief Enumeration for pin direction.
 */
typedef enum {
    Input,  /**< Pin direction input */
    Output  /**< Pin direction output */
} Direction_t;

/**
 * @brief Enumeration for pin logic level.
 */
typedef enum {
    Low,  /**< Pin logic level low */
    High  /**< Pin logic level high */
} Logic_t;

/**
 * @brief Structure to hold pin configuration.
 */
typedef struct {
    char port;               /**< Port of the pin (A, B, C, D) */
    char pin;                /**< Pin number */
    Direction_t direction;   /**< Direction of the pin (Input, Output) */
    Logic_t logic;           /**< Logic level of the pin (Low, High) */
} Pin_config_t;

/**
 * @brief Sets the pin logic level to high.
 *
 * @param Pin Pointer to the pin configuration structure.
 * @return Std_return ROK if successful, NOK if the pin configuration is null.
 */
Std_return Pin_Set(Pin_config_t *Pin);

/**
 * @brief Sets the pin logic level to low.
 *
 * @param Pin Pointer to the pin configuration structure.
 * @return Std_return ROK if successful, NOK if the pin configuration is null.
 */
Std_return Pin_Clear(Pin_config_t *Pin);

/**
 * @brief Toggles the pin logic level.
 *
 * @param Pin Pointer to the pin configuration structure.
 * @return Std_return ROK if successful, NOK if the pin configuration is null.
 */
Std_return Pin_Toggle(Pin_config_t *Pin);

/**
 * @brief Reads the current logic level of the pin.
 *
 * @param Pin Pointer to the pin configuration structure.
 * @param level Pointer to a variable where the current logic level of the pin will be stored.
 * @return Std_return ROK if successful, NOK if the pin configuration or the level pointer is null.
 */
Std_return Pin_Read(Pin_config_t *Pin, Logic_t *level);

/**
 * @brief Sets the pin direction to input or output.
 *
 * @param Pin Pointer to the pin configuration structure.
 * @return Std_return ROK if successful, NOK if the pin configuration is null.
 */
Std_return Pin_Direction(Pin_config_t *Pin);

/**
 * @brief Initializes the pin direction and sets its logic level.
 *
 * @param Pin Pointer to the pin configuration structure.
 * @return Std_return ROK if successful, NOK if the pin configuration is null.
 */
Std_return Pin_logic_init(Pin_config_t *Pin);

/**
 * @brief Writes the logic level to the specified pin.
 *
 * @param Pin Pointer to the pin configuration structure.
 * @param volt The logic level to be written to the pin (Low, High).
 * @return Std_return ROK if successful, NOK if the pin configuration is null.
 */
Std_return Pin_write(Pin_config_t *Pin, Logic_t volt);

/**
 * @brief Sets the entire port to a specific value.
 *
 * @param port The port to be set (A, B, C, D).
 * @param value The value to set the port to.
 * @return Std_return ROK if successful, NOK if the port is invalid.
 */
Std_return Port_Set(char port, uint8_t value);

/**
 * @brief Clears the entire port (sets all pins to low).
 *
 * @param port The port to be cleared (A, B, C, D).
 * @return Std_return ROK if successful, NOK if the port is invalid.
 */
Std_return Port_Clear(char port);

/**
 * @brief Toggles the entire port (inverts all pin values).
 *
 * @param port The port to be toggled (A, B, C, D).
 * @return Std_return ROK if successful, NOK if the port is invalid.
 */
Std_return Port_Toggle(char port);

/**
 * @brief Reads the current value of the port.
 *
 * @param port The port to be read (A, B, C, D).
 * @param value Pointer to a variable where the current port value will be stored.
 * @return Std_return ROK if successful, NOK if the port or value pointer is invalid.
 */
Std_return Port_Read(char port, uint8_t *value);

/**
 * @brief Sets the direction of the entire port (input or output).
 *
 * @param port The port to set the direction for (A, B, C, D).
 * @param direction The direction to set the port to (Input, Output).
 * @return Std_return ROK if successful, NOK if the port is invalid.
 */
Std_return Port_Direction(char port, Direction_t direction);

#endif /* GPIO_H_ */
