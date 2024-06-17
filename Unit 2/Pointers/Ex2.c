#include <stdio.h>


int main()  {


    char alphabet[27] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i <27 ; ++i) {
        printf("%c  ", *(alphabet + i));
    }
    return 0;
}


