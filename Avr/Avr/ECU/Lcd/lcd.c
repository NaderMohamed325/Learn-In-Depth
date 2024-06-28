/*
 * File:   lcd.c
 * Author: Nader
 *
 * 
 */

#include "lcd.h"

/**
 * @brief   Sends a 4-bit command to the LCD.
 * @param   Lcd: Pointer to the lcd_4bit_mode structure.
 * @param   data_command: The 4-bit command to be sent to the LCD.
 * @return  Returns ROK if the command is sent successfully, otherwise NOK.
 */
Std_return static lcd_4bits_command(lcd_4bit_mode  *Lcd, unsigned char data_command);

/**
 * @brief   Sends an enable pulse to the LCD in 4-bit mode.
 * @param   Lcd: Pointer to the lcd_4bit_mode structure.
 * @return  Returns ROK if the enable pulse is sent successfully, otherwise NOK.
 */
Std_return static lcd_4bits_send_enable(lcd_4bit_mode  *Lcd);

/**
 * @brief   Sends an enable pulse to the LCD in 8-bit mode.
 * @param   Lcd: Pointer to the lcd_8bit_mode structure.
 * @return  Returns ROK if the enable pulse is sent successfully, otherwise NOK.
 */
Std_return static lcd_8bits_send_enable(lcd_8bit_mode  *Lcd);

/**
 * @brief   Sets the cursor position for a 4-bit LCD.
 * @param   Lcd: Pointer to the lcd_4bit_mode structure.
 * @param   row: The row number (starting from 0).
 * @param   column: The column number (starting from 0).
 * @return  Returns ROK if the cursor position is set successfully, otherwise NOK.
 */
Std_return static lcd_4bit_set_cursor(lcd_4bit_mode  *Lcd, unsigned char row, unsigned char column);

/**
 * @brief   Sets the cursor position for an 8-bit LCD.
 * @param   Lcd: Pointer to the lcd_8bit_mode structure.
 * @param   row: The row number (starting from 0).
 * @param   column: The column number (starting from 0).
 * @return  Returns ROK if the cursor position is set successfully, otherwise NOK.
 */
Std_return static lcd_8bit_set_cursor(lcd_8bit_mode  *Lcd, unsigned char row, unsigned char column);

/**
 * @brief   Initializes the LCD in 4-bit mode.
 * @details Initializes the control pins and data pins of the LCD in 4-bit mode.
 * @param   Lcd: Pointer to the lcd_4bit_mode structure.
 * @return  Returns ROK if initialization is successful, otherwise NOK.
 */
Std_return lcd_4bit_initialize(lcd_4bit_mode  *Lcd) {
    Std_return ret = ROK;
    if (NULL == Lcd) {
        ret = NOK;
    } else {
        ret = Pin_logic_init(&(Lcd->lcd_en));
        ret = Pin_logic_init(&(Lcd->lcd_rs));
        for (unsigned char i = 0; i < 4; i++) {
            ret = Pin_logic_init(&(Lcd->lcd_data[i]));
        }
        _delay_ms(20);
        ret = lcd_4bit_send_command(Lcd, _LCD_8BIT_MODE_2_LINE);
        _delay_ms(5);
        ret = lcd_4bit_send_command(Lcd, _LCD_8BIT_MODE_2_LINE);
        _delay_us(150);
        ret = lcd_4bit_send_command(Lcd, _LCD_8BIT_MODE_2_LINE);

        ret = lcd_4bit_send_command(Lcd, _LCD_CLEAR);
        ret = lcd_4bit_send_command(Lcd, _LCD_RETURN_HOME);
        ret = lcd_4bit_send_command(Lcd, _LCD_ENTRY_MODE_INC_SHIFT_OFF);
        ret = lcd_4bit_send_command(Lcd, _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
        ret = lcd_4bit_send_command(Lcd, _LCD_4BIT_MODE_2_LINE);
        ret = lcd_4bit_send_command(Lcd, 0x80);
    }
    return ret;
}

/**
 * @brief   Sends a command to the LCD in 4-bit mode.
 * @param   Lcd: Pointer to the lcd_4bit_mode structure.
 * @param   command: The command to be sent to the LCD.
 * @return  Returns ROK if the command is sent successfully, otherwise NOK.
 */
Std_return lcd_4bit_send_command(lcd_4bit_mode  *Lcd, unsigned char command) {
    Std_return ret = ROK;
    if (NULL == Lcd) {
        ret = NOK;
    } else {
        ret = Pin_write(&(Lcd->lcd_rs), Low);
        ret = lcd_4bits_command(Lcd, command >> 4);
        ret = lcd_4bits_send_enable(Lcd);
        ret = lcd_4bits_command(Lcd, command);
        ret = lcd_4bits_send_enable(Lcd);
    }
    return ret;
}

/**
 * @brief   Sends character data to the LCD in 4-bit mode.
 * @param   Lcd: Pointer to the lcd_4bit_mode structure.
 * @param   data: The character data to be sent to the LCD.
 * @return  Returns ROK if the data is sent successfully, otherwise NOK.
 */
Std_return lcd_4bit_send_char_data(lcd_4bit_mode  *Lcd, unsigned char data) {
    Std_return ret = ROK;
    if (NULL == Lcd) {
        ret = NOK;
    } else {
        ret = Pin_write(&(Lcd->lcd_rs), High);
        ret = lcd_4bits_command(Lcd, data >> 4);
        ret = lcd_4bits_send_enable(Lcd);
        ret = lcd_4bits_command(Lcd, data);
        ret = lcd_4bits_send_enable(Lcd);
    }
    return ret;
}

/**
 * @brief   Sends character data to the specified position on the LCD in 4-bit mode.
 * @param   Lcd: Pointer to the lcd_4bit_mode structure.
 * @param   row: The row number (starting from 0).
 * @param   column: The column number (starting from 0).
 * @param   data: The character data to be sent to the LCD.
 * @return  Returns ROK if the data is sent successfully, otherwise NOK.
 */
Std_return lcd_4bit_send_char_data_pos(lcd_4bit_mode  *Lcd, unsigned char row, unsigned char column, unsigned char data) {
    Std_return ret = ROK;
    if (NULL == Lcd) {
        ret = NOK;
    } else {
        ret = lcd_4bit_set_cursor(Lcd, row, column);
        ret = lcd_4bit_send_char_data(Lcd, data);
    }
    return ret;
}

/**
 * @brief   Sends a string to the LCD in 4-bit mode.
 * @param   Lcd: Pointer to the lcd_4bit_mode structure.
 * @param   str: Pointer to the string to be sent to the LCD.
 * @return  Returns ROK if the string is sent successfully, otherwise NOK.
 */
Std_return lcd_4bit_send_string(lcd_4bit_mode  *Lcd, unsigned char *str) {
    Std_return ret = ROK;
    if (NULL == Lcd) {
        ret = NOK;
    } else {
        while (*str) {
            ret = lcd_4bit_send_char_data(Lcd, *str++);
        }
    }
    return ret;
}

/**
 * @brief   Sends a string to the specified position on the LCD in 4-bit mode.
 * @param   Lcd: Pointer to the lcd_4bit_mode structure.
 * @param   row: The row number (starting from 0).
 * @param   column: The column number (starting from 0).
 * @param   str: Pointer to the string to be sent to the LCD.
 * @return  Returns ROK if the string is sent successfully, otherwise NOK.
 */
Std_return lcd_4bit_send_string_pos(lcd_4bit_mode  *Lcd, unsigned char row, unsigned char column, unsigned char *str) {
    Std_return ret = ROK;
    if (NULL == Lcd) {
        ret = NOK;
    } else {
        ret = lcd_4bit_set_cursor(Lcd, row, column);
        ret = lcd_4bit_send_string(Lcd, str);
    }
    return ret;
}

/**
 * @brief   Sends a custom character to the specified position on the LCD in 4-bit mode.
 * @param   Lcd: Pointer to the lcd_4bit_mode structure.
 * @param   row: The row number (starting from 0).
 * @param   column: The column number (starting from 0).
 * @param   _char: Array containing the custom character data.
 * @param   mem_pos: Memory position for the custom character (0 to 7).
 * @return  Returns ROK if the custom character is sent successfully, otherwise NOK.
 */
Std_return lcd_4bit_send_custom_ch(lcd_4bit_mode  *Lcd, unsigned char row, unsigned char column, unsigned char  _char[], unsigned char mem_pos) {
    Std_return ret = ROK;
    if (NULL == Lcd) {
        ret = NOK;
    } else {
        ret = lcd_4bit_send_command(Lcd, _LCD_CGRAM_START + 8 * mem_pos);
        for (unsigned char i = 0; i < 8; i++) {
            ret = lcd_4bit_send_char_data(Lcd, _char[i]);
        }
        ret = lcd_4bit_send_char_data_pos(Lcd, row, column, mem_pos);


    }
    return ret;
}

/**
 * @brief   Initializes the LCD in 8-bit mode.
 * @details Initializes the control pins and data pins of the LCD in 8-bit mode.
 * @param   Lcd: Pointer to the lcd_8bit_mode structure.
 * @return  Returns ROK if initialization is successful, otherwise NOK.
 */
Std_return lcd_8bit_initailize(lcd_8bit_mode  *Lcd) {
    Std_return ret = ROK;
    if (NULL == Lcd) {
        ret = NOK;
    } else {
        ret = Pin_logic_init(&(Lcd->lcd_en));
        ret = Pin_logic_init(&(Lcd->lcd_rs));
        for (unsigned char i = 0; i < 8; i++) {
            ret = Pin_logic_init(&(Lcd->lcd_data[i]));
        }
        _delay_ms(20);
        ret = lcd_8bit_send_command(Lcd, _LCD_8BIT_MODE_2_LINE);
        _delay_ms(5);
        ret = lcd_8bit_send_command(Lcd, _LCD_8BIT_MODE_2_LINE);
        _delay_us(150);
        ret = lcd_8bit_send_command(Lcd, _LCD_8BIT_MODE_2_LINE);

        ret = lcd_8bit_send_command(Lcd, _LCD_CLEAR);
        ret = lcd_8bit_send_command(Lcd, _LCD_RETURN_HOME);
        ret = lcd_8bit_send_command(Lcd, _LCD_ENTRY_MODE_INC_SHIFT_OFF);
        ret = lcd_8bit_send_command(Lcd, _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
        ret = lcd_8bit_send_command(Lcd, _LCD_8BIT_MODE_2_LINE);
        ret = lcd_8bit_send_command(Lcd, 0x80);
    }
    return ret;
}

/**
 * @brief   Sends a command to the LCD in 8-bit mode.
 * @param   Lcd: Pointer to the lcd_8bit_mode structure.
 * @param   command: The command to be sent to the LCD.
 * @return  Returns ROK if the command is sent successfully, otherwise NOK.
 */
Std_return lcd_8bit_send_command(lcd_8bit_mode  *Lcd, unsigned char command) {
    Std_return ret = ROK;
    if (NULL == Lcd) {
        ret = NOK;
    } else {
        ret = Pin_write(&(Lcd->lcd_rs), Low);
        for (unsigned char i = 0; i < 8; i++) {
            ret = Pin_write(&(Lcd->lcd_data[i]), ((command) >> i) & 0X01);
        }
        ret = lcd_8bits_send_enable(Lcd);
    }
    return ret;
}

/**
 * @brief   Sends character data to the LCD in 8-bit mode.
 * @param   Lcd: Pointer to the lcd_8bit_mode structure.
 * @param   data: The character data to be sent to the LCD.
 * @return  Returns ROK if the data is sent successfully, otherwise NOK.
 */
Std_return lcd_8bit_send_char_data(lcd_8bit_mode  *Lcd, unsigned char data) {
    Std_return ret = ROK;
    if (NULL == Lcd) {
        ret = NOK;
    } else {
        ret = Pin_write(&(Lcd->lcd_rs), High);
        for (unsigned char i = 0; i < 8; i++) {
            ret = Pin_write(&(Lcd->lcd_data[i]), ((data) >> i) & 0X01);
        }
        ret = lcd_8bits_send_enable(Lcd);
    }
    return ret;
}

/**
 * @brief   Sends character data to the specified position on the LCD in 8-bit mode.
 * @param   Lcd: Pointer to the lcd_8bit_mode structure.
 * @param   row: The row number (starting from 0).
 * @param   column: The column number (starting from 0).
 * @param   data: The character data to be sent to the LCD.
 * @return  Returns ROK if the data is sent successfully, otherwise NOK.
 */
Std_return lcd_8bit_send_char_data_pos(lcd_8bit_mode  *Lcd, unsigned char row, unsigned char column, unsigned char data) {
    Std_return ret = ROK;
    if (NULL == Lcd) {
        ret = NOK;
    } else {
        ret = lcd_8bit_set_cursor(Lcd, row, column);
        ret = lcd_8bit_send_char_data(Lcd, data);
    }
    return ret;
}

Std_return lcd_8bit_send_string(lcd_8bit_mode  *Lcd, unsigned char *str) {
    Std_return ret = ROK;
    if (NULL == Lcd) {
        ret = NOK;
    } else {
        while (*str) {
            ret = lcd_8bit_send_char_data(Lcd, *str++);
        }
    }

    return ret;
}

Std_return lcd_8bit_send_string_pos(lcd_8bit_mode  *Lcd, unsigned char row, unsigned char column, unsigned char *str) {
    Std_return ret = ROK;
    if (NULL == Lcd) {
        ret = NOK;
    } else {
        ret = lcd_8bit_set_cursor(Lcd, row, column);
        ret = lcd_8bit_send_string(Lcd, str);
    }

    return ret;
}

Std_return lcd_8bit_send_custom_ch(lcd_8bit_mode  *Lcd, unsigned char row, unsigned char column, unsigned char  _char[], unsigned char mem_pos) {
    Std_return ret = ROK;
    if (NULL == Lcd) {
        ret = NOK;
    } else {
        ret = lcd_8bit_send_command(Lcd, _LCD_CGRAM_START + 8 * mem_pos);
        for (unsigned char i = 0; i < 8; i++) {
            ret = lcd_8bit_send_char_data(Lcd, _char[i]);
        }
        ret = lcd_8bit_send_char_data_pos(Lcd, row, column, mem_pos);



    }

    return ret;
}

Std_return static lcd_8bits_send_enable(lcd_8bit_mode  *Lcd) {
    Std_return ret = ROK;
    if (NULL == Lcd) {
        ret = NOK;
    } else {
        ret = Pin_write(&(Lcd->lcd_en), High);
        _delay_us(5);
        ret = Pin_write(&(Lcd->lcd_en), Low);
    }
    return ret;
}

Std_return static lcd_8bit_set_cursor(lcd_8bit_mode  *Lcd, unsigned char row, unsigned char column) {
    Std_return ret = ROK;
    if (NULL == Lcd) {
        ret = NOK;
    } else {
        column--;
        switch (row) {
            case ROW1:
                ret = lcd_8bit_send_command(Lcd, (0X80 + column));
                break;
            case ROW2:
                ret = lcd_8bit_send_command(Lcd, (0x0c + column));
                break;
            case ROW3:
                ret = lcd_8bit_send_command(Lcd, (0X94 + column));
                break;
            case ROW4:
                ret = lcd_8bit_send_command(Lcd, (0XD4 + column));
                break;
            default:;
        }
    }
    return ret;
}

Std_return convert_byte_to_string(unsigned char value, char *str) {
    Std_return ret = ROK;
    if (NULL == str) {
        ret = NOK;
    } else {
        memset(str, '0', 4);
        sprintf(str, "%i", value);
    }

    return ret;
}

Std_return convert_short_to_string(int value, char *str) {
	Std_return ret = ROK;
	if (NULL == str) {
		ret = NOK;
		} else {
		memset(str, '\0', 6);  // Clear the buffer of length 6 (including null terminator)
		sprintf(str, "%i", value);  // Convert value to string and store in str
	}

	return ret;
}


Std_return convert_int_to_string(int value, char *str) {
	Std_return ret = ROK;
	if (NULL == str) {
		ret = NOK;
		} else {
		memset(str, '\0', 11);  // Clear the buffer of length 11 (including null terminator)
		sprintf(str, "%i", value);  // Convert value to string and store in str
	}

	return ret;
}

Std_return static lcd_4bits_send_enable(lcd_4bit_mode  *Lcd) {
    Std_return ret = ROK;
    if (NULL == Lcd) {
        ret = NOK;
    } else {
        ret = Pin_write(&(Lcd->lcd_en), High);
        _delay_us(5);
        ret = Pin_write(&(Lcd->lcd_en), Low);
    }
    return ret;
}

Std_return static lcd_4bits_command(lcd_4bit_mode  *Lcd, unsigned char data_command) {
    Std_return ret = ROK;
    ret = Pin_write(&(Lcd->lcd_data[0]), (data_command >> 0) & (unsigned char) 0x01);
    ret = Pin_write(&(Lcd->lcd_data[1]), (data_command >> 1) & (unsigned char) 0x01);
    ret = Pin_write(&(Lcd->lcd_data[2]), (data_command >> 2) & (unsigned char) 0x01);
    ret = Pin_write(&(Lcd->lcd_data[3]), (data_command >> 3) & (unsigned char) 0x01);
    return ret;
}

Std_return static lcd_4bit_set_cursor(lcd_4bit_mode  *Lcd, unsigned char row, unsigned char column) {
    Std_return ret = ROK;
    column--;
    switch (row) {
        case ROW1: ret = lcd_4bit_send_command(Lcd, (0x80 + column));
            break;
        case ROW2: ret = lcd_4bit_send_command(Lcd, (0xc0 + column));
            break;
        case ROW3: ret = lcd_4bit_send_command(Lcd, (0x94 + column));
            break;
        case ROW4: ret = lcd_4bit_send_command(Lcd, (0xd4 + column));
            break;
        default:;
    }
    return ret;
}