#include <stdio.h>
#include <string.h>

int main() {


    char str[100];
    fgets(str, sizeof(str), stdin);
    printf("You entered: %s", str);
    printf("\nReversed: ");
    char *pt = str + strlen(str) ;
    while (pt != str-1) {
        printf("%c", *pt);
        pt--;
    }
}


