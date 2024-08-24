#include "MCAL/gpio/gpio.h"
#include "ECU/Keypad/keypad.h"
#include <stdbool.h>

#define PASSWORD_LENGTH 4

char password_user[PASSWORD_LENGTH] = "xxxx";
char password_ans[PASSWORD_LENGTH] = "1234";

Pin_config_t Green, Red;
Keypad_t keypad;

/**
 * @brief Initializes the LED pins.
 */
void Init_LEDs(void) {
    Green.direction = Output;
    Green.logic = Low;
    Green.pin = 0;
    Green.port = B;
    Pin_logic_init(&Green);

    Red.direction = Output;
    Red.logic = Low;
    Red.pin = 1;
    Red.port = B;
    Pin_logic_init(&Red);
}

/**
 * @brief Initializes the keypad pins.
 */
void Init_Keypad(void) {
    // Initialize keypad rows
    for (int i = 0; i < 4; i++) {
        keypad.keypad_row_pins[i].direction = Output;
        keypad.keypad_row_pins[i].logic = Low;
        keypad.keypad_row_pins[i].pin = i;
        keypad.keypad_row_pins[i].port = C;
    }

    // Initialize keypad columns
    for (int i = 0; i < 4; i++) {
        keypad.keypad_col_pins[i].direction = Input;
        keypad.keypad_col_pins[i].logic = Low;
        keypad.keypad_col_pins[i].pin = i;
        keypad.keypad_col_pins[i].port = D;
    }

    // Initialize keypad
    keypad_initialize(&keypad);
}

/**
 * @brief Reads the user input password using the keypad.
 */
void Read_Password(void) {
    unsigned char key = 0;
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        while (1) {
            keypad_get_value(&keypad, &key);
            if (key != 'x') {  // Assuming 'x' is not a valid key press
                password_user[i] = key;
                break;
            }
        }
    }
}

/**
 * @brief Checks if the entered password matches the stored password.
 * @return True if the passwords match, otherwise false.
 */
bool Check_Password(void) {
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        if (password_ans[i] != password_user[i]) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Resets the user password and turns off both LEDs.
 */
void Reset_Password(void) {
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        password_user[i] = 'x';
    }

    Green.logic = Low;
    Red.logic = Low;
    Pin_logic_init(&Green);
    Pin_logic_init(&Red);
}

/**
 * @brief Controls the LED states based on the password check.
 * @param is_password_correct Indicates if the entered password is correct.
 */
void Update_LED_Status(bool is_password_correct) {
    if (is_password_correct) {
        Green.logic = High;
        Red.logic = Low;
    } else {
        Green.logic = Low;
        Red.logic = High;
    }
    Pin_logic_init(&Green);
    Pin_logic_init(&Red);
}

int main(void) {
    // Initialize LEDs and Keypad
    Init_LEDs();
    Init_Keypad();

    while (1) {
        Read_Password();
        bool is_password_correct = Check_Password();
        Update_LED_Status(is_password_correct);
        _delay_ms(1000);
        Reset_Password();
    }

    return 0;
}
