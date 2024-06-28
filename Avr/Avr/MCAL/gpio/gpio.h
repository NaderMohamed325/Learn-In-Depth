/*
* gpio.h
*
* Created: 6/28/2024 6:13:21 PM
*  Author: Nader
*/

#ifndef GPIO_H_
#define GPIO_H_

#include "Memory_Map.h"
#include "Utils.h"

#define A 0
#define B 1
#define C 2
#define D 3

#define F_CPU 8000000UL
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

#endif /* GPIO_H_ */
