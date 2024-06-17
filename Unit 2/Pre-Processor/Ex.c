#include "stdio.h"

#define area(r) (3.14*r*r)

int main(){
    int r;
    printf("Enter tha radius: ");
    scanf("%d", &r);
    double result = area(r);
    printf("The Area is: %0.2f", result);

}
