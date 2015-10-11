#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // if there's only one argument, return an error!
    // This program only works with two command line arguments, the
    // first being the program being executed, and the second being
    // the numeric used to encrypt.
    if(argc == 1)
    {
        printf("Err\n");
        return 1;
    }
    // as long as an argument exists, we'll assume that "int key = atoi(argv[1])" will NOT fail.
    else
    {
        // ask user for phrase to encrypt, and extract key.
        string phrase = GetString();
        int key = atoi(argv[1]);
        
        // the key can be ANY number, but it has to be reduced down to a number between 1 and 26.
        while(key > 26)
        {
            key = key - 26;
        }
        
        // loop through the phrase
        for(int i = 0, n = strlen(phrase); i < n; i++)
        {
            // if the character is an alphabetic character, act on it.
            if(isalpha(phrase[i]))
            {
                // check if adding the key will result in an alphabetic character
                // per the ASCII assignments. if so, print it.
                if(isalpha(phrase[i] + key))
                {
                    printf("%c", phrase[i] + key);
                }
                // if not, you have to loop BACK to the beginning alphabet.
                // ex. "zzz" with a key of 2 will result in "bbb"
                else
                {
                    printf("%c", phrase[i] + key - 26);
                }
            }
            // if the character is NOT an alphabetic character, do nothing.
            else
            {
                printf("%c", phrase[i]);
            }
        }
        
        // print new line to end.
        printf("\n");
    }
}
