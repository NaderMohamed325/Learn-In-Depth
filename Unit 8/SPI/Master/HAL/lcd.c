/*
 * lcd.c
 *
 *  Created on: Jun 30, 2024
 *      Author: xcite
 */

#include "inc/lcd.h"
GPIO_PinConfig_t PinCfg;



void LCD_GPIO_init()
{
    PinCfg.GPIO_PinNumber = RS_SWITCH;
    PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
    PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
    MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

    PinCfg.GPIO_PinNumber = RW_SWITCH;
    PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
    PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
    MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

    PinCfg.GPIO_PinNumber = EN_SWITCH;
    PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
    PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
    MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

    // SET THE NEXT 4 PINS AS Output
    PinCfg.GPIO_PinNumber = GPIO_PIN_4;
    PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
    PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
    MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

    PinCfg.GPIO_PinNumber = GPIO_PIN_5;
    PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
    PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
    MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

    PinCfg.GPIO_PinNumber = GPIO_PIN_6;
    PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
    PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
    MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

    PinCfg.GPIO_PinNumber = GPIO_PIN_7;
    PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
    PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
    MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

    MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, GPIO_PIN_RESET);
    MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_RESET);
    MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);
}

void LCD_clear_screen()
{
    LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}

void LCD_lcd_kick()
{
    MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, GPIO_PIN_SET);
    delay_ms(2);
    MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, GPIO_PIN_RESET);
}

void LCD_GOTO_XY(unsigned char line, unsigned char position)
{
    if (line == 1)
    {
        if (position < 16 && position >= 0)
        {
            LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW + position);
        }
    }
    if (line == 2)
    {
        if (position < 16 && position >= 0)
        {
            LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW + position);
        }
    }
}

void LCD_INIT()
{
    delay_ms(20);
    LCD_GPIO_init();
    delay_ms(15);

    // Set to 4-bit mode
    LCD_WRITE_COMMAND(0x02); // Initialize LCD in 4-bit mode
    LCD_WRITE_COMMAND(LCD_FUNCTION_4BIT_2LINES);
    LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
    LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
    LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
}

void LCD_check_lcd_isbusy()
{
    PinCfg.GPIO_PinNumber = GPIO_PIN_4;
    PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
    MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

    PinCfg.GPIO_PinNumber = GPIO_PIN_5;
    PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
    MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

    PinCfg.GPIO_PinNumber = GPIO_PIN_6;
    PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
    MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

    PinCfg.GPIO_PinNumber = GPIO_PIN_7;
    PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
    MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

    MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_SET);
    MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_RESET);
    LCD_lcd_kick();
    MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);

    PinCfg.GPIO_PinNumber = GPIO_PIN_4;
    PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
    PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
    MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

    PinCfg.GPIO_PinNumber = GPIO_PIN_5;
    PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
    PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
    MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

    PinCfg.GPIO_PinNumber = GPIO_PIN_6;
    PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
    PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
    MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

    PinCfg.GPIO_PinNumber = GPIO_PIN_7;
    PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
    PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
    MCAL_GPIO_Init(LCD_CTRL, &PinCfg);
}

void LCD_WRITE_COMMAND(unsigned char command)
{
    // Send high nibble
    MCAL_GPIO_WritePort(LCD_CTRL, (MCAL_GPIO_ReadPort(LCD_CTRL) & 0x0F) | (command & 0xF0));
    MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);
    MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_RESET);
    LCD_lcd_kick();

    // Send low nibble
    MCAL_GPIO_WritePort(LCD_CTRL, (MCAL_GPIO_ReadPort(LCD_CTRL) & 0x0F) | ((command << 4) & 0xF0));
    MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);
    MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_RESET);
    LCD_lcd_kick();
}

void LCD_WRITE_CHAR(unsigned char character)
{
    // Send high nibble
    MCAL_GPIO_WritePort(LCD_CTRL, (MCAL_GPIO_ReadPort(LCD_CTRL) & 0x0F) | (character & 0xF0));
    MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);
    MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_SET);
    LCD_lcd_kick();

    // Send low nibble
    MCAL_GPIO_WritePort(LCD_CTRL, (MCAL_GPIO_ReadPort(LCD_CTRL) & 0x0F) | ((character << 4) & 0xF0));
    MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);
    MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_SET);
    LCD_lcd_kick();
}

void LCD_WRITE_STRING(char *string)
{
    int count = 0;
    while (*string > 0)
    {
        count++;
        LCD_WRITE_CHAR(*string++);
        if (count == 16)
        {
            LCD_GOTO_XY(2, 0);
        }
        else if (count == 32)
        {
            LCD_clear_screen();
            LCD_GOTO_XY(1, 0);
            count = 0;
        }
    }
}
