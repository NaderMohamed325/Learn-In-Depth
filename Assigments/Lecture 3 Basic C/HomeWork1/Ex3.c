/*
EX3:

Write C Program to Add Two Integers

i should see the Console as following:
##########Console-output###
Enter two integers: 12
11
Sum: 23
###########################
*/
#include <stdio.h>

int main()
{
    printf("Enter two integers: ");
    int var1,var2;
    scanf("%i%i",&var1,&var2);
    printf("sum : %i ",var1+var2);
}
