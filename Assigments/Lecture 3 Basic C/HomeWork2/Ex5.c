#include <stdio.h>

int main()
{

    char c;
    printf("Enter the char : ");
    scanf("%c",&c);
    if((c>='a' && c<='z') || ((c>='A' && c<='Z')) )
    {
        printf("its an alphabet");
    }
    else
    {
        printf("it is not an alphabet");
    }

}
