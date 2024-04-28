//
// Created by xcite on 4/16/2024.
//

#include <stdio.h>
#include <stdbool.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

bool check_prime(int n) {
    bool is_prime = true;


    if (n == 0 || n == 1) {
        is_prime = false;
    }

    for (int i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            is_prime = false;
            break;
        }
    }

    return is_prime;
}

void interval_prime(int l, int r) {
    l = MIN(l, r);
    r = MAX(l, r);
    for (int i = l; i <= r; ++i) {
        if (check_prime(i)) {
            printf("%i ", i);
        }
    }
}

int main() {
    int l, r;
    printf("Enter the interval\r\n");
    scanf_s("%i%i", &l, &r);
    interval_prime(l,r);
}