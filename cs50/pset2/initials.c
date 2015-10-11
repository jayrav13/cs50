#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // request string entry by user, use first letter as first initial
    string name = GetString();
    printf("%c", toupper(name[0]));
    
    // loop through balance of name. wherever a space is detected, assume following character is an initial
    for(int i = 0, n = strlen(name); i < n; i++)
    {
        if(isalpha(name[i]) == false)
        {
            printf("%c", toupper(name[i+1]));
        }
    }
    
    // print new line
    printf("\n");
}
