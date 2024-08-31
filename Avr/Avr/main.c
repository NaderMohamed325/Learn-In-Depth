#include "ECU/Keypad/keypad.h"
#include "ECU/Lcd/lcd.h"
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

lcd_4bit_mode lcd;
Keypad_t keypad;
void Init(void);
char val;

void DisplayQuestion(int question_id);
bool CheckAnswer(int question_id, char answer);

void Questions(void) {
	lcd_4bit_send_command(&lcd, _LCD_CLEAR);
	int question_id = rand() % 5 + 1; // Random question number between 1 and 5

	DisplayQuestion(question_id);

	val = '\0'; // Reset value before getting the input

	// Wait for the user to press a key
	while (val == '\0') {
		keypad_get_value(&keypad, &val);
	}

	// Display the pressed key
	lcd_4bit_send_char_data_pos(&lcd, 1, 0, val);

	// Check if the answer is correct
	if (CheckAnswer(question_id, val)) {
		lcd_4bit_send_command(&lcd, _LCD_CLEAR);
		lcd_4bit_send_string(&lcd, " Correct!");
		} else {
		lcd_4bit_send_command(&lcd, _LCD_CLEAR);
		lcd_4bit_send_string(&lcd, " Wrong!");
	}

	_delay_ms(1000); // Wait for a second before showing the next question
}

void DisplayQuestion(int question_id) {
	switch(question_id) {
		case 1:
		lcd_4bit_send_string(&lcd, " 10 - 2 = ?");
		break;
		case 2:
		lcd_4bit_send_string(&lcd, " 7 - 3 = ?");
		break;
		case 3:
		lcd_4bit_send_string(&lcd, " 6 / 2 = ?");
		break;
		case 4:
		lcd_4bit_send_string(&lcd, " 8 / 2 = ?");
		break;
		case 5:
		lcd_4bit_send_string(&lcd, " 5 - 5 = ?");
		break;
	}
}

bool CheckAnswer(int question_id, char answer) {
	switch(question_id) {
		case 1: return answer == '8';  // Correct answer for "10 - 2 = ?"
		case 2: return answer == '4';  // Correct answer for "7 - 3 = ?"
		case 3: return answer == '3';  // Correct answer for "6 / 2 = ?"
		case 4: return answer == '4';  // Correct answer for "8 / 2 = ?"
		case 5: return answer == '0';  // Correct answer for "5 - 5 = ?"
		default: return false;
	}
}

int main(void) {
	srand((unsigned)time(NULL)); // Seed the random number generator
	Init();
	
	while (1) {
		Questions();
	}
	
	return 0;
}

void Init(void) {
	// Initialize LCD pins
	lcd.lcd_rs.direction = Output;
	lcd.lcd_rs.logic = Low;
	lcd.lcd_rs.pin = 0;
	lcd.lcd_rs.port = A;

	lcd.lcd_en.direction = Output;
	lcd.lcd_en.logic = Low;
	lcd.lcd_en.pin = 1;
	lcd.lcd_en.port = A;

	for (int i = 0; i < 4; i++) {
		lcd.lcd_data[i].direction = Output;
		lcd.lcd_data[i].logic = Low;
		lcd.lcd_data[i].pin = i + 2; // Pins 2, 3, 4, 5
		lcd.lcd_data[i].port = A;
	}

	// Initialize the LCD
	lcd_4bit_initialize(&lcd);

	// Initialize Keypad row pins
	for (int i = 0; i < 4; i++) {
		keypad.keypad_row_pins[i].direction = Output;
		keypad.keypad_row_pins[i].logic = Low;
		keypad.keypad_row_pins[i].pin = i;
		keypad.keypad_row_pins[i].port = C;
	}

	// Initialize Keypad column pins
	for (int i = 0; i < 4; i++) {
		keypad.keypad_col_pins[i].direction = Input;
		keypad.keypad_col_pins[i].logic = Low;
		keypad.keypad_col_pins[i].pin = i;
		keypad.keypad_col_pins[i].port = D;
	}

	// Initialize the keypad
	keypad_initialize(&keypad);
}
