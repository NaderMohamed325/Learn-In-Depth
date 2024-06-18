#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CA.h"

// Global variables
int CA_speed = 0, CA_distance = 0, CA_threshold = 50;
void (*CA_state)();

// Function prototypes
int US_get_distance_random(int l, int r, int count);

// State function definitions
STATE_define(CA_waiting) {
    CA_speed = 0;
    CA_distance = US_get_distance_random(45, 55, 1);  // Get a random distance

    if (CA_distance <= CA_threshold) {
        CA_state = STATE(CA_waiting);
    } else {
        CA_state = STATE(CA_driving);
    }

    printf("waiting function: speed=%d, distance=%d\n", CA_speed, CA_distance);


}
STATE_define(CA_driving) {
    CA_speed = 30;
    CA_distance = US_get_distance_random(45, 55, 1);  // Get a random distance

    if (CA_distance <= CA_threshold) {
        CA_state = STATE(CA_waiting);
    } else {
        CA_state = STATE(CA_driving);
    }

    printf("driving function: speed=%d, distance=%d\n", CA_speed, CA_distance);

}

int US_get_distance_random(int l, int r, int count) {
    int i, distance = 0;
    for (i = 0; i < count; i++) {
        distance = (rand() % (r - l + 1)) + l;
    }
    return distance;
}
