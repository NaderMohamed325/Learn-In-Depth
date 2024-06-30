/*
 * lcd.c
 *
 *  Created on: Jun 30, 2024
 *      Author: xcite
 */
#include "inc/lcd.h"

/**
 * @brief   Sends a 4-bit command to the LCD.
 * @param   Lcd: Pointer to the lcd_4bit_mode structure.
 * @param   data_command: The 4-bit command to be sent to the LCD.
 * @return  Returns E_OK if the command is sent successfully, otherwise E_NOT_OK.
 */
void static lcd_4bits_command(lcd_4bit_mode  *Lcd, uint8_t data_command);

/**
 * @brief   Sends an enable pulse to the LCD in 4-bit mode.
 * @param   Lcd: Pointer to the lcd_4bit_mode structure.
 * @return  Returns E_OK if the enable pulse is sent successfully, otherwise E_NOT_OK.
 */
void static lcd_4bits_send_enable(lcd_4bit_mode  *Lcd);

/**
 * @brief   Sends an enable pulse to the LCD in 8-bit mode.
 * @param   Lcd: Pointer to the lcd_8bit_mode structure.
 * @return  Returns E_OK if the enable pulse is sent successfully, otherwise E_NOT_OK.
 */
void static lcd_8bits_send_enable(lcd_8bit_mode  *Lcd);

/**
 * @brief   Sets the cursor position for a 4-bit LCD.
 * @param   Lcd: Pointer to the lcd_4bit_mode structure.
 * @param   row: The row number (starting from 0).
 * @param   column: The column number (starting from 0).
 * @return  Returns E_OK if the cursor position is set successfully, otherwise E_NOT_OK.
 */
void static lcd_4bit_set_cursor(lcd_4bit_mode  *Lcd, uint8_t row,
	uint8_t column);

/**
 * @brief   Sets the cursor position for an 8-bit LCD.
 * @param   Lcd: Pointer to the lcd_8bit_mode structure.
 * @param   row: The row number (starting from 0).
 * @param   column: The column number (starting from 0).
 * @return  Returns E_OK if the cursor position is set successfully, otherwise E_NOT_OK.
 */
void static lcd_8bit_set_cursor(lcd_8bit_mode  *Lcd, uint8_t row,
	uint8_t column);

/**
 * @brief   Initializes the LCD in 4-bit mode.
 * @details Initializes the control pins and data pins of the LCD in 4-bit mode.
 * @param   Lcd: Pointer to the lcd_4bit_mode structure.
 * @return  Returns E_OK if initialization is successful, otherwise E_NOT_OK.
 */
void lcd_4bit_initailize(lcd_4bit_mode  *Lcd)
    {

    MCAL_GPIO_Init(Lcd->lcd_en.GPIOx, &(Lcd->lcd_en.Pin));
    MCAL_GPIO_Init(Lcd->lcd_rs.GPIOx, &(Lcd->lcd_rs.Pin));

    for (uint8_t i = 0; i < 4; i++)
	{
	MCAL_GPIO_Init(Lcd->lcd_data[i].GPIOx, &(Lcd->lcd_data[i].Pin));
	}
    delay(20);
    lcd_4bit_send_command(Lcd, _LCD_8BIT_MODE_2_LINE);
    delay(5);
    lcd_4bit_send_command(Lcd, _LCD_8BIT_MODE_2_LINE);
    delay(1);
    lcd_4bit_send_command(Lcd, _LCD_8BIT_MODE_2_LINE);

    lcd_4bit_send_command(Lcd, _LCD_CLEAR);
    lcd_4bit_send_command(Lcd, _LCD_RETURN_HOME);
    lcd_4bit_send_command(Lcd, _LCD_ENTRY_MODE_INC_SHIFT_OFF);
    lcd_4bit_send_command(Lcd, _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
    lcd_4bit_send_command(Lcd, _LCD_4BIT_MODE_2_LINE);
    lcd_4bit_send_command(Lcd, 0x80);

    }

/**
 * @brief   Sends a command to the LCD in 4-bit mode.
 * @param   Lcd: Pointer to the lcd_4bit_mode structure.
 * @param   command: The command to be sent to the LCD.
 * @return  Returns E_OK if the command is sent successfully, otherwise E_NOT_OK.
 */
void lcd_4bit_send_command(lcd_4bit_mode  *Lcd, uint8_t command)
    {

    MCAL_GPIO_WritePin(Lcd->lcd_rs.GPIOx, Lcd->lcd_rs.Pin.GPIO_PinNumber,
    GPIO_PIN_RESET);
    lcd_4bits_command(Lcd, command >> 4);
    lcd_4bits_send_enable(Lcd);
    lcd_4bits_command(Lcd, command);
    lcd_4bits_send_enable(Lcd);

    }

/**
 * @brief   Sends character data to the LCD in 4-bit mode.
 * @param   Lcd: Pointer to the lcd_4bit_mode structure.
 * @param   data: The character data to be sent to the LCD.
 * @return  Returns E_OK if the data is sent successfully, otherwise E_NOT_OK.
 */
void lcd_4bit_send_char_data(lcd_4bit_mode  *Lcd, uint8_t data)
    {

    MCAL_GPIO_WritePin(Lcd->lcd_rs.GPIOx, Lcd->lcd_rs.Pin.GPIO_PinNumber,
    GPIO_PIN_SET);
    lcd_4bits_command(Lcd, data >> 4);
    lcd_4bits_send_enable(Lcd);
    lcd_4bits_command(Lcd, data);
    lcd_4bits_send_enable(Lcd);

    }

/**
 * @brief   Sends character data to the specified position on the LCD in 4-bit mode.
 * @param   Lcd: Pointer to the lcd_4bit_mode structure.
 * @param   row: The row number (starting from 0).
 * @param   column: The column number (starting from 0).
 * @param   data: The character data to be sent to the LCD.
 * @return  Returns E_OK if the data is sent successfully, otherwise E_NOT_OK.
 */
void lcd_4bit_send_char_data_pos(lcd_4bit_mode  *Lcd, uint8_t row,
	uint8_t column, uint8_t data)
    {

    lcd_4bit_set_cursor(Lcd, row, column);
    lcd_4bit_send_char_data(Lcd, data);

    }

/**
 * @brief   Sends a string to the LCD in 4-bit mode.
 * @param   Lcd: Pointer to the lcd_4bit_mode structure.
 * @param   str: Pointer to the string to be sent to the LCD.
 * @return  Returns E_OK if the string is sent successfully, otherwise E_NOT_OK.
 */
void lcd_4bit_send_string(lcd_4bit_mode  *Lcd, uint8_t *str)
    {

    while (*str)
	{
	lcd_4bit_send_char_data(Lcd, *str++);
	}

    }

/**
 * @brief   Sends a string to the specified position on the LCD in 4-bit mode.
 * @param   Lcd: Pointer to the lcd_4bit_mode structure.
 * @param   row: The row number (starting from 0).
 * @param   column: The column number (starting from 0).
 * @param   str: Pointer to the string to be sent to the LCD.
 * @return  Returns E_OK if the string is sent successfully, otherwise E_NOT_OK.
 */
void lcd_4bit_send_string_pos(lcd_4bit_mode  *Lcd, uint8_t row,
	uint8_t column, uint8_t *str)
    {

    lcd_4bit_set_cursor(Lcd, row, column);
    lcd_4bit_send_string(Lcd, str);

    }

/**
 * @brief   Sends a custom character to the specified position on the LCD in 4-bit mode.
 * @param   Lcd: Pointer to the lcd_4bit_mode structure.
 * @param   row: The row number (starting from 0).
 * @param   column: The column number (starting from 0).
 * @param   _char: Array containing the custom character data.
 * @param   mem_pos: Memory position for the custom character (0 to 7).
 * @return  Returns E_OK if the custom character is sent successfully, otherwise E_NOT_OK.
 */
void lcd_4bit_send_custom_ch(lcd_4bit_mode  *Lcd, uint8_t row,
	uint8_t column, uint8_t  _char[], uint8_t mem_pos)
    {

  lcd_4bit_send_command(Lcd, _LCD_CGRAM_START + 8 * mem_pos);
    for (uint8_t i = 0; i < 8; i++)
	{
	lcd_4bit_send_char_data(Lcd, _char[i]);
	}
    lcd_4bit_send_char_data_pos(Lcd, row, column, mem_pos);

    }

/**
 * @brief   Initializes the LCD in 8-bit mode.
 * @details Initializes the control pins and data pins of the LCD in 8-bit mode.
 * @param   Lcd: Pointer to the lcd_8bit_mode structure.
 * @return  Returns E_OK if initialization is successful, otherwise E_NOT_OK.
 */
void lcd_8bit_initailize(lcd_8bit_mode  *Lcd)
    {
    MCAL_GPIO_Init(Lcd->lcd_rs.GPIOx, & (Lcd->lcd_rs.Pin));
    MCAL_GPIO_Init(Lcd->lcd_en.GPIOx, & (Lcd->lcd_en.Pin));

    for (uint8_t i = 0; i < 8; i++)
	{
	MCAL_GPIO_Init(Lcd->lcd_data[i].GPIOx, &Lcd->lcd_data[i].Pin);

	}
    delay(20);
    lcd_8bit_send_command(Lcd, _LCD_8BIT_MODE_2_LINE);
    delay(5);
    lcd_8bit_send_command(Lcd, _LCD_8BIT_MODE_2_LINE);
    delay(1);
    lcd_8bit_send_command(Lcd, _LCD_8BIT_MODE_2_LINE);

    lcd_8bit_send_command(Lcd, _LCD_CLEAR);
    lcd_8bit_send_command(Lcd, _LCD_RETURN_HOME);
    lcd_8bit_send_command(Lcd, _LCD_ENTRY_MODE_INC_SHIFT_OFF);
    lcd_8bit_send_command(Lcd, _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
    lcd_8bit_send_command(Lcd, _LCD_8BIT_MODE_2_LINE);
    lcd_8bit_send_command(Lcd, 0x80);

    }

/**
 * @brief   Sends a command to the LCD in 8-bit mode.
 * @param   Lcd: Pointer to the lcd_8bit_mode structure.
 * @param   command: The command to be sent to the LCD.
 * @return  Returns E_OK if the command is sent successfully, otherwise E_NOT_OK.
 */
void lcd_8bit_send_command(lcd_8bit_mode  *Lcd, uint8_t command)
    {

    MCAL_GPIO_WritePin(Lcd->lcd_rs.GPIOx, Lcd->lcd_rs.Pin.GPIO_PinNumber,
	    GPIO_PIN_RESET);
    for (uint8_t i = 0; i < 8; i++)
	{

	MCAL_GPIO_WritePin(Lcd->lcd_data[i].GPIOx,
		Lcd->lcd_rs.Pin.GPIO_PinNumber, ((command) >> i) & 1);
	}
    lcd_8bits_send_enable(Lcd);

    }

/**
 * @brief   Sends character data to the LCD in 8-bit mode.
 * @param   Lcd: Pointer to the lcd_8bit_mode structure.
 * @param   data: The character data to be sent to the LCD.
 * @return  Returns E_OK if the data is sent successfully, otherwise E_NOT_OK.
 */
void lcd_8bit_send_char_data(lcd_8bit_mode  *Lcd, uint8_t data)
    {

    MCAL_GPIO_WritePin(Lcd->lcd_rs.GPIOx, Lcd->lcd_rs.Pin.GPIO_PinNumber,
	    GPIO_PIN_SET);

    for (uint8_t i = 0; i < 8; i++)
	{
	MCAL_GPIO_WritePin(Lcd->lcd_data[i].GPIOx,
		Lcd->lcd_rs.Pin.GPIO_PinNumber, ((data) >> i) & 1);

	}
    lcd_8bits_send_enable(Lcd);

    }

/**
 * @brief   Sends character data to the specified position on the LCD in 8-bit mode.
 * @param   Lcd: Pointer to the lcd_8bit_mode structure.
 * @param   row: The row number (starting from 0).
 * @param   column: The column number (starting from 0).
 * @param   data: The character data to be sent to the LCD.
 * @return  Returns E_OK if the data is sent successfully, otherwise E_NOT_OK.
 */
void lcd_8bit_send_char_data_pos(lcd_8bit_mode  *Lcd, uint8_t row,
	uint8_t column, uint8_t data)
    {

    lcd_8bit_set_cursor(Lcd, row, column);
    lcd_8bit_send_char_data(Lcd, data);

    }

void lcd_8bit_send_string(lcd_8bit_mode  *Lcd, uint8_t *str)
    {

    while (*str)
	{
	lcd_8bit_send_char_data(Lcd, *str++);
	}

    }

void lcd_8bit_send_string_pos(lcd_8bit_mode  *Lcd, uint8_t row,
	uint8_t column, uint8_t *str)
    {

    lcd_8bit_set_cursor(Lcd, row, column);
    lcd_8bit_send_string(Lcd, str);

    }

void lcd_8bit_send_custom_ch(lcd_8bit_mode  *Lcd, uint8_t row,
	uint8_t column, uint8_t  _char[], uint8_t mem_pos)
    {

    lcd_8bit_send_command(Lcd, _LCD_CGRAM_START + 8 * mem_pos);
    for (uint8_t i = 0; i < 8; i++)
	{
	lcd_8bit_send_char_data(Lcd, _char[i]);
	}
    lcd_8bit_send_char_data_pos(Lcd, row, column, mem_pos);

    }

void static lcd_8bits_send_enable(lcd_8bit_mode  *Lcd)
    {


    MCAL_GPIO_WritePin(Lcd->lcd_en.GPIOx, Lcd->lcd_en.Pin.GPIO_PinNumber,
	    GPIO_PIN_SET);

    delay(1);
    MCAL_GPIO_WritePin(Lcd->lcd_en.GPIOx, Lcd->lcd_en.Pin.GPIO_PinNumber,
	    GPIO_PIN_RESET);

    }

void static lcd_8bit_set_cursor(lcd_8bit_mode  *Lcd, uint8_t row,
	uint8_t column)
    {

    column--;
    switch (row)
	{
    case ROW1:
	lcd_8bit_send_command(Lcd, (0X80 + column));
	break;
    case ROW2:
	lcd_8bit_send_command(Lcd, (0x0c + column));
	break;
    case ROW3:
	lcd_8bit_send_command(Lcd, (0X94 + column));
	break;
    case ROW4:
	lcd_8bit_send_command(Lcd, (0XD4 + column));
	break;
    default:
	;
	}

    }

void convert_byte_to_string(uint8_t value, char *str)
    {

    memset(str, '0', 4);
    sprintf(str, "%i", value);

    }

void convert_short_to_string(uint16_t value, char *str)
    {

    memset(str, '\0', 6);
    sprintf(str, "%i", value);

    }

void convert_int_to_string(int value, char *str)
    {

    memset(str, '\0', 11);
    sprintf(str, "%i", value);

    }

void static lcd_4bits_send_enable(lcd_4bit_mode  *Lcd)
    {

    MCAL_GPIO_WritePin(Lcd->lcd_en.GPIOx, Lcd->lcd_en.Pin.GPIO_PinNumber,
	    GPIO_PIN_SET);
    delay(1);
    MCAL_GPIO_WritePin(Lcd->lcd_en.GPIOx, Lcd->lcd_en.Pin.GPIO_PinNumber,
	    GPIO_PIN_RESET);

    }

void static lcd_4bits_command(lcd_4bit_mode  *Lcd, uint8_t data_command)
    {
    for (uint8_t i = 0; i < 4; i++)
	MCAL_GPIO_WritePin(Lcd->lcd_data[i].GPIOx,
		Lcd->lcd_rs.Pin.GPIO_PinNumber,
		(data_command >> i) & (uint8_t) 0x01);

    }

void static lcd_4bit_set_cursor(lcd_4bit_mode  *Lcd, uint8_t row,
	uint8_t column)
    {

    switch (row)
	{
    case ROW1:
	 lcd_4bit_send_command(Lcd, (0x80 + column));
	break;
    case ROW2:
	 lcd_4bit_send_command(Lcd, (0xc0 + column));
	break;
    case ROW3:
	 lcd_4bit_send_command(Lcd, (0x94 + column));
	break;
    case ROW4:
	 lcd_4bit_send_command(Lcd, (0xd4 + column));
	break;

	}

    }
