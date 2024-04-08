#include<stdio.h>

int main()
{
    int var;
    printf("Enter a number you want to check : ");
    scanf("%i",&var);
    if(var%2==0)
        printf("Even");
    else
        printf("Odd");

    return 0;
}
