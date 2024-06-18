/*
 * CA.h
 *
 *  Created on: Jun 18, 2024
 *      Author: xcite
 */

#ifndef CA_H_
#define CA_H_

#include "state.h"

// Function declarations
STATE_define(CA_waiting);
STATE_define(CA_driving);

// State pointer
extern void (*CA_state)();

// State IDs
typedef enum {
    CA_waiting,
    CA_driving,
} CA_state_id;

#endif /* CA_H_ */
