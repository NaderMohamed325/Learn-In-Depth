#include <stdio.h>

struct Length {
    int feet;
    int inches;
};

struct Length addLengths(struct Length l1, struct Length l2) {
    struct Length result;
    result.inches = l1.inches + l2.inches;
    result.feet = l1.feet + l2.feet + (result.inches / 12);
    result.inches %= 12;
    return result;
}

int main() {
    struct Length length1, length2, sum;
    printf("Enter length 1 (feet inches): ");
    scanf("%d %d", &length1.feet, &length1.inches);
    printf("Enter length 2 (feet inches): ");
    scanf("%d %d", &length2.feet, &length2.inches);
    sum = addLengths(length1, length2);
    printf("Sum: %d feet %d inches\n", sum.feet, sum.inches);
    return 0;
}
