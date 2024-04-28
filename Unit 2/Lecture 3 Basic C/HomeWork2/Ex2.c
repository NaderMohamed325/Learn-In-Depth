#include <stdio.h>
#include <ctype.h>

#define or ||
int main()
{

    char c;
    printf("Enter the Char : ");
    scanf("%c",&c);


    c = tolower(c);

    if(c=='a' or c=='o' or c=='e' or c=='i' or c=='u')
    {
        printf("%c is a vowel.\n",c);
    }
    else
    {
        printf("%c is a consonant.\n",c);
    }

    return 0;
}
