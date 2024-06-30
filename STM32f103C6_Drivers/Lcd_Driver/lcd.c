/*
 * lcd.c
 *
 *  Created on: Jun 30, 2024
 *      Author: xcite
 */
#include "inc/lcd.h"

#define LCD_COMMAND 0
#define LCD_DATA 1

static void lcd_4bits_send_enable(lcd_4bit_mode *Lcd);
static void lcd_4bits_command(lcd_4bit_mode *Lcd, uint8_t data_command);
static void lcd_4bit_set_cursor(lcd_4bit_mode *Lcd, uint8_t row, uint8_t column);
static void lcd_8bits_send_enable(lcd_8bit_mode *Lcd);
static void lcd_8bit_set_cursor(lcd_8bit_mode *Lcd, uint8_t row, uint8_t column);

void lcd_4bit_initialize(lcd_4bit_mode *Lcd) {
    MCAL_GPIO_Init(Lcd->lcd_en.GPIOx, &(Lcd->lcd_en.Pin));
    MCAL_GPIO_Init(Lcd->lcd_rs.GPIOx, &(Lcd->lcd_rs.Pin));
    for (uint8_t i = 0; i < 4; i++) {
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

void lcd_4bit_send_command(lcd_4bit_mode *Lcd, uint8_t command) {
    MCAL_GPIO_WritePin(Lcd->lcd_rs.GPIOx, Lcd->lcd_rs.Pin.GPIO_PinNumber, GPIO_PIN_RESET);
    lcd_4bits_command(Lcd, command >> 4);
    lcd_4bits_send_enable(Lcd);
    lcd_4bits_command(Lcd, command);
    lcd_4bits_send_enable(Lcd);
}

void lcd_4bit_send_char_data(lcd_4bit_mode *Lcd, uint8_t data) {
    MCAL_GPIO_WritePin(Lcd->lcd_rs.GPIOx, Lcd->lcd_rs.Pin.GPIO_PinNumber, GPIO_PIN_SET);
    lcd_4bits_command(Lcd, data >> 4);
    lcd_4bits_send_enable(Lcd);
    lcd_4bits_command(Lcd, data);
    lcd_4bits_send_enable(Lcd);
}

void lcd_4bit_send_char_data_pos(lcd_4bit_mode *Lcd, uint8_t row, uint8_t column, uint8_t data) {
    lcd_4bit_set_cursor(Lcd, row, column);
    lcd_4bit_send_char_data(Lcd, data);
}

void lcd_4bit_send_string(lcd_4bit_mode *Lcd, uint8_t *str) {
    while (*str) {
        lcd_4bit_send_char_data(Lcd, *str++);
    }
}

void lcd_4bit_send_string_pos(lcd_4bit_mode *Lcd, uint8_t row, uint8_t column, uint8_t *str) {
    lcd_4bit_set_cursor(Lcd, row, column);
    lcd_4bit_send_string(Lcd, str);
}

void lcd_4bit_send_custom_ch(lcd_4bit_mode *Lcd, uint8_t row, uint8_t column, uint8_t _char[], uint8_t mem_pos) {
    lcd_4bit_send_command(Lcd, _LCD_CGRAM_START + 8 * mem_pos);
    for (uint8_t i = 0; i < 8; i++) {
        lcd_4bit_send_char_data(Lcd, _char[i]);
    }
    lcd_4bit_send_char_data_pos(Lcd, row, column, mem_pos);
}

void lcd_8bit_initialize(lcd_8bit_mode *Lcd) {
    MCAL_GPIO_Init(Lcd->lcd_rs.GPIOx, &(Lcd->lcd_rs.Pin));
    MCAL_GPIO_Init(Lcd->lcd_en.GPIOx, &(Lcd->lcd_en.Pin));
    for (uint8_t i = 0; i < 8; i++) {
        MCAL_GPIO_Init(Lcd->lcd_data[i].GPIOx, &(Lcd->lcd_data[i].Pin));
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

void lcd_8bit_send_command(lcd_8bit_mode *Lcd, uint8_t command) {
    MCAL_GPIO_WritePin(Lcd->lcd_rs.GPIOx, Lcd->lcd_rs.Pin.GPIO_PinNumber, GPIO_PIN_RESET);
    for (uint8_t i = 0; i < 8; i++) {
        MCAL_GPIO_WritePin(Lcd->lcd_data[i].GPIOx, Lcd->lcd_rs.Pin.GPIO_PinNumber, ((command) >> i) & 1);
    }
    lcd_8bits_send_enable(Lcd);
}

void lcd_8bit_send_char_data(lcd_8bit_mode *Lcd, uint8_t data) {
    MCAL_GPIO_WritePin(Lcd->lcd_rs.GPIOx, Lcd->lcd_rs.Pin.GPIO_PinNumber, GPIO_PIN_SET);
    for (uint8_t i = 0; i < 8; i++) {
        MCAL_GPIO_WritePin(Lcd->lcd_data[i].GPIOx, Lcd->lcd_rs.Pin.GPIO_PinNumber, ((data) >> i) & 1);
    }
    lcd_8bits_send_enable(Lcd);
}

void lcd_8bit_send_char_data_pos(lcd_8bit_mode *Lcd, uint8_t row, uint8_t column, uint8_t data) {
    lcd_8bit_set_cursor(Lcd, row, column);
    lcd_8bit_send_char_data(Lcd, data);
}

void lcd_8bit_send_string(lcd_8bit_mode *Lcd, uint8_t *str) {
    while (*str) {
        lcd_8bit_send_char_data(Lcd, *str++);
    }
}

void lcd_8bit_send_string_pos(lcd_8bit_mode *Lcd, uint8_t row, uint8_t column, uint8_t *str) {
    lcd_8bit_set_cursor(Lcd, row, column);
    lcd_8bit_send_string(Lcd, str);
}

void lcd_8bit_send_custom_ch(lcd_8bit_mode *Lcd, uint8_t row, uint8_t column, uint8_t _char[], uint8_t mem_pos) {
    lcd_8bit_send_command(Lcd, _LCD_CGRAM_START + 8 * mem_pos);
    for (uint8_t i = 0; i < 8; i++) {
        lcd_8bit_send_char_data(Lcd, _char[i]);
    }
    lcd_8bit_send_char_data_pos(Lcd, row, column, mem_pos);
}

static void lcd_8bits_send_enable(lcd_8bit_mode *Lcd) {
    MCAL_GPIO_WritePin(Lcd->lcd_en.GPIOx, Lcd->lcd_en.Pin.GPIO_PinNumber, GPIO_PIN_SET);
    delay(1);
    MCAL_GPIO_WritePin(Lcd->lcd_en.GPIOx, Lcd->lcd_en.Pin.GPIO_PinNumber, GPIO_PIN_RESET);
}

static void lcd_8bit_set_cursor(lcd_8bit_mode *Lcd, uint8_t row, uint8_t column) {
    static const uint8_t row_offsets[] = {0x00, 0x40, 0x14, 0x54};
    lcd_8bit_send_command(Lcd, 0x80 | (column + row_offsets[row]));
}

static void lcd_4bits_send_enable(lcd_4bit_mode *Lcd) {
    MCAL_GPIO_WritePin(Lcd->lcd_en.GPIOx, Lcd->lcd_en.Pin.GPIO_PinNumber, GPIO_PIN_SET);
    delay(1);
    MCAL_GPIO_WritePin(Lcd->lcd_en.GPIOx, Lcd->lcd_en.Pin.GPIO_PinNumber, GPIO_PIN_RESET);
}

static void lcd_4bits_command(lcd_4bit_mode *Lcd, uint8_t data_command) {
    for (uint8_t i = 0; i < 4; i++) {
        MCAL_GPIO_WritePin(Lcd->lcd_data[i].GPIOx, Lcd->lcd_data[i].Pin.GPIO_PinNumber, (data_command >> i) & 1);
    }
}

static void lcd_4bit_set_cursor(lcd_4bit_mode *Lcd, uint8_t row, uint8_t column) {
    static const uint8_t row_offsets[] = {0x00, 0x40, 0x14, 0x54};
    lcd_4bit_send_command(Lcd, 0x80 | (column + row_offsets[row]));
}
