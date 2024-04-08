/*
EX2:

Write C Program to Print a Integer Entered by a User
i should see the Console as following:
##########Console-output###
Enter a integer: 25
You entered: 25
###########################
*/

#include <stdio.h>

int main()
{
    printf("Enter a integer: ");
    int var;
    scanf("%i",&var);
    printf("You entered: %i ",var);
}
