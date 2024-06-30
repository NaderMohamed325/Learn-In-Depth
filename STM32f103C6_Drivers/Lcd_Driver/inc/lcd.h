/*
 * lcd.h
 *
 *  Created on: Jun 30, 2024
 *      Author: xcite
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_
#include "../../GPIO/inc/stm32f103c6_gpio.h"
#include <string.h>
/*---------------- MACROS --------------------*/
// LCD Commands
#define _LCD_CLEAR                      0X01
#define _LCD_RETURN_HOME                0x02
#define _LCD_ENTRY_MODE_DEC_SHIFT_OFF   0x04
#define _LCD_ENTRY_MODE_DEC_SHIFT_ON    0x05
#define _LCD_ENTRY_MODE_INC_SHIFT_OFF   0x06
#define _LCD_ENTRY_MODE_INC_SHIFT_ON    0x07
#define _LCD_CURSOR_MOVE_SHIFT_LEFT     0x10
#define _LCD_CURSOR_MOVE_SHIFT_RIGHT    0x14
#define _LCD_DISPLAY_SHIFT_LEFT         0x18
#define _LCD_DISPLAY_SHIFT_RIGHT        0x1C
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF 0x0C
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON  0x0D
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_OFF  0x0E
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_ON   0x0F
#define _LCD_DISPLAY_OFF_CURSOR_OFF              0x08
#define _LCD_8BIT_MODE_2_LINE           0x38
#define _LCD_4BIT_MODE_2_LINE           0x28

#define _LCD_CGRAM_START                0x40
#define _LCD_DDRAM_START                0x80

#define ROW1 1
#define ROW2 2
#define ROW3 3
#define ROW4 4

/*---------------- DATA TYPES -----------------*/

/**
 * @struct lcd_4bit_mode
 * @brief Structure representing the configuration for 4-bit mode LCD.
 * @param lcd_rs: GPIO configuration for LCD RS pin.
 * @param lcd_en: GPIO configuration for LCD EN pin.
 * @param lcd_data: Array of GPIO configurations for LCD data pins (4 bits).
 */
typedef struct {
    GPIO_PinConfig_t Pin;
    GPIO_TypeDef *GPIOx;
}Lcd_PinCfg_t;
typedef struct {
    Lcd_PinCfg_t lcd_rs; /**< GPIO configuration for LCD RS pin. */
    Lcd_PinCfg_t lcd_en; /**< GPIO configuration for LCD EN pin. */
    Lcd_PinCfg_t lcd_data[4]; /**< Array of GPIO configurations for LCD data pins (4 bits). */
} lcd_4bit_mode;

/**
 * @struct lcd_8bit_mode
 * @brief Structure representing the configuration for 8-bit mode LCD.
 * @param lcd_rs: GPIO configuration for LCD RS pin.
 * @param lcd_en: GPIO configuration for LCD EN pin.
 * @param lcd_data: Array of GPIO configurations for LCD data pins (8 bits).
 */
typedef struct {
    Lcd_PinCfg_t lcd_rs; /**< GPIO configuration for LCD RS pin. */
    Lcd_PinCfg_t lcd_en; /**< GPIO configuration for LCD EN pin. */
    Lcd_PinCfg_t lcd_data[8]; /**< Array of GPIO configurations for LCD data pins (8 bits). */
} lcd_8bit_mode;

/**
 * @brief Initializes the LCD in 4-bit mode.
 * @details Initializes the control pins and data pins of the LCD in 4-bit mode.
 * @param Lcd: Pointer to the lcd_4bit_mode structure.
 * @return Returns E_OK if initialization is successful, otherwise E_NOT_OK.
 */
void lcd_4bit_initailize(lcd_4bit_mode  *Lcd);

/**
 * @brief Sends a command to the LCD in 4-bit mode.
 * @param Lcd: Pointer to the lcd_4bit_mode structure.
 * @param command: The command to be sent to the LCD.
 * @return Returns E_OK if the command is sent successfully, otherwise E_NOT_OK.
 */
void lcd_4bit_send_command(lcd_4bit_mode  *Lcd, uint8_t command);

/**
 * @brief Sends character data to the LCD in 4-bit mode.
 * @param Lcd: Pointer to the lcd_4bit_mode structure.
 * @param data: The character data to be sent to the LCD.
 * @return Returns E_OK if the data is sent successfully, otherwise E_NOT_OK.
 */
void lcd_4bit_send_char_data(lcd_4bit_mode  *Lcd, uint8_t data);

/**
 * @brief Sends character data to the specified position on the LCD in 4-bit mode.
 * @param Lcd: Pointer to the lcd_4bit_mode structure.
 * @param row: The row number (starting from 0).
 * @param column: The column number (starting from 0).
 * @param data: The character data to be sent to the LCD.
 * @return Returns E_OK if the data is sent successfully, otherwise E_NOT_OK.
 */
void lcd_4bit_send_char_data_pos(lcd_4bit_mode  *Lcd, uint8_t row, uint8_t column, uint8_t data);

/**
 * @brief Sends a string to the LCD in 4-bit mode.
 * @param Lcd: Pointer to the lcd_4bit_mode structure.
 * @param str: Pointer to the string to be sent to the LCD.
 * @return Returns E_OK if the string is sent successfully, otherwise E_NOT_OK.
 */
void lcd_4bit_send_string(lcd_4bit_mode  *Lcd, uint8_t *str);

/**
 * @brief Sends a string to the specified position on the LCD in 4-bit mode.
 * @param Lcd: Pointer to the lcd_4bit_mode structure.
 * @param row: The row number (starting from 0).
 * @param column: The column number (starting from 0).
 * @param str: Pointer to the string to be sent to the LCD.
 * @return Returns E_OK if the string is sent successfully, otherwise E_NOT_OK.
 */
void lcd_4bit_send_string_pos(lcd_4bit_mode  *Lcd, uint8_t row, uint8_t column, uint8_t *str);

/**
 * @brief Sends a custom character to the specified position on the LCD in 4-bit mode.
 * @param Lcd: Pointer to the lcd_4bit_mode structure.
 * @param row: The row number (starting from 0).
 * @param column: The column number (starting from 0).
 * @param _char: Array representing the custom character.
 * @param mem_pos: Memory position for storing the custom character (0 to 7).
 * @return Returns E_OK if the custom character is sent successfully, otherwise E_NOT_OK.
 */
void lcd_4bit_send_custom_ch(lcd_4bit_mode  *Lcd, uint8_t row, uint8_t column, uint8_t  _char[], uint8_t mem_pos);

/**
 * @brief Initializes the LCD in 8-bit mode.
 * @details Initializes the control pins and data pins of the LCD in 8-bit mode.
 * @param Lcd: Pointer to the lcd_8bit_mode structure.
 * @return Returns E_OK if initialization is successful, otherwise E_NOT_OK.
 */
void lcd_8bit_initailize(lcd_8bit_mode  *Lcd);

/**
 * @brief Sends a command to the LCD in 8-bit mode.
 * @param Lcd: Pointer to the lcd_8bit_mode structure.
 * @param command: The command to be sent to the LCD.
 * @return Returns E_OK if the command is sent successfully, otherwise E_NOT_OK.
 */
void lcd_8bit_send_command(lcd_8bit_mode  *Lcd, uint8_t command);

/**
 * @brief Sends character data to the LCD in 8-bit mode.
 * @param Lcd: Pointer to the lcd_8bit_mode structure.
 * @param data: The character data to be sent to the LCD.
 * @return Returns E_OK if the data is sent successfully, otherwise E_NOT_OK.
 */
void lcd_8bit_send_char_data(lcd_8bit_mode  *Lcd, uint8_t data);

/**
 * @brief Sends character data to the specified position on the LCD in 8-bit mode.
 * @param Lcd: Pointer to the lcd_8bit_mode structure.
 * @param row: The row number (starting from 0).
 * @param column: The column number (starting from 0).
 * @param data: The character data to be sent to the LCD.
 * @return Returns E_OK if the data is sent successfully, otherwise E_NOT_OK.
 */
void lcd_8bit_send_char_data_pos(lcd_8bit_mode  *Lcd, uint8_t row, uint8_t column, uint8_t data);

/**
 * @brief Sends a string to the LCD in 8-bit mode.
 * @param Lcd: Pointer to the lcd_8bit_mode structure.
 * @param str: Pointer to the string to be sent to the LCD.
 * @return Returns E_OK if the string is sent successfully, otherwise E_NOT_OK.
 */
void lcd_8bit_send_string(lcd_8bit_mode  *Lcd, uint8_t *str);

/**
 * @brief Sends a string to the specified position on the LCD in 8-bit mode.
 * @param Lcd: Pointer to the lcd_8bit_mode structure.
 * @param row: The row number (starting from 0).
 * @param column: The column number (starting from 0).
 * @param str: Pointer to the string to be sent to the LCD.
 * @return Returns E_OK if the string is sent successfully, otherwise E_NOT_OK.
 */
void lcd_8bit_send_string_pos(lcd_8bit_mode  *Lcd, uint8_t row, uint8_t column, uint8_t *str);

/**
 * @brief Sends a custom character to the specified position on the LCD in 8-bit mode.
 * @param Lcd: Pointer to the lcd_8bit_mode structure.
 * @param row: The row number (starting from 0).
 * @param column: The column number (starting from 0).
 * @param _char: Array representing the custom character.
 * @param mem_pos: Memory position for storing the custom character (0 to 7).
 * @return Returns E_OK if the custom character is sent successfully, otherwise E_NOT_OK.
 */
void lcd_8bit_send_custom_ch(lcd_8bit_mode  *Lcd, uint8_t row, uint8_t column, uint8_t  _char[], uint8_t mem_pos);

/**
 * @brief Converts a byte value to a string.
 * @param value: The byte value to be converted.
 * @param str: Pointer to the destination string.
 * @return Returns E_OK if conversion is successful, otherwise E_NOT_OK.
 */
void convert_byte_to_string(uint8_t value, char *str);

/**
 * @brief Converts a short value to a string.
 * @param value: The short value to be converted.
 * @param str: Pointer to the destination string.
 * @return Returns E_OK if conversion is successful, otherwise E_NOT_OK.
 */
void convert_short_to_string(uint16_t value, char *str);

/**
 * @brief Converts an integer value to a string.
 * @param value: The integer value to be converted.
 * @param str: Pointer to the destination string.
 * @return Returns E_OK if conversion is successful, otherwise E_NOT_OK.
 */
void convert_int_to_string(int value, char *str);


#endif /* INC_LCD_H_ */
