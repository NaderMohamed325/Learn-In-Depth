#include <stdio.h>

int main() {
    int size;
    printf("Enter the size: ");
    fflush(stdout);
    scanf("%i", &size);

    int a[size + 1];

    printf("Enter the elements: ");
    for (int i = 0; i < size; ++i) {
        scanf("%i", &a[i]);
    }

    printf("Enter the element and the index: ");
    fflush(stdout);
    int element, pos;
    scanf("%i%i", &element, &pos);


    for (int i = size; i >= pos; --i) {
        a[i] = a[i - 1];
    }

    a[pos - 1] = element;

    printf("The array after insertion: ");
    for (int i = 0; i <= size; ++i) {
        printf("%i  ", a[i]);
    }

    return 0;
}
