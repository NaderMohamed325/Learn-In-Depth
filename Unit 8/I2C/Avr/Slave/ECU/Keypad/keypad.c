/*
 * keypad.c
 *
 * Created: 7/4/2024 8:47:52 PM
 *  Author: xcite
 */ 
/*------------ FUNCTION DECLARATIONS ----------*/
/**
 * @brief Initializes the keypad.
 * @param keypad Pointer to a Keypad_t structure containing the keypad configuration.
 * @return Standard return type indicating success or failure.
 */
#include "keypad.h"
 static  unsigned char btn_values[ECU_KEYPAD_ROW][ECU_KEYPAD_COL] = {
	{'7', '8', '9', '/'},
	{'4', '5', '6', '*'},
	{'1', '2', '3', '-'},
	{'#', '0', '=', '+'}
};

void keypad_initialize( Keypad_t *keypad){
	// Initialize each row pin of the keypad
	for (int i = 0; i < ECU_KEYPAD_ROW; i++) {
	 Pin_logic_init(&(keypad->keypad_row_pins[i]));
	}
	
	// Initialize each column pin of the keypad
	for (int i = 0; i < ECU_KEYPAD_COL; i++) {
	 Pin_logic_init(&(keypad->keypad_col_pins[i]));
	}
}

/**
 * @brief Retrieves the value from the keypad.
 * @param keypad Pointer to a Keypad_t structure containing the keypad configuration.
 * @param value Reference parameter to store the retrieved value.
 * @return Standard return type indicating success or failure.
 */
void keypad_get_value( Keypad_t *keypad,  unsigned char *value){
	 for (int i = 0; i < ECU_KEYPAD_ROW; i++) {
		 Logic_t value_pin = 0;

		 // Set all rows to GPIO_LOW
		 for (int j = 0; j < ECU_KEYPAD_ROW; j++) {
		 Pin_write(&(keypad->keypad_row_pins[j]), Low);
		 }

		 // Set the current row to GPIO_HIGH
		  Pin_write(&(keypad->keypad_row_pins[i]), High);
		 
		 _delay_ms(30);  // You may need to adjust this delay based on your requirements

		 // Read the columns
		 for (int j = 0; j < ECU_KEYPAD_COL; j++) {
			 Pin_Read(&(keypad->keypad_col_pins[j]), &value_pin);

			 // Check if the button is pressed (GPIO_HIGH)
			 if (value_pin == High) {
				 *value = btn_values[i][j];
				 break;  // Exit the loop once a button is found
			 }
		 }
}

}