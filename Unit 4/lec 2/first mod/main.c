/*
 * main.c
 *
 *  Created on: Jun 18, 2024
 *      Author: xcite
 */

#include <stdio.h>
#include "CA.h"

void setup() {
    CA_state = STATE(CA_waiting);
}

int main() {
    setup();

    while (1) {
        CA_state();
    }

    return 0;
}
