#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

// declaring a method to be shown later on.
bool containsNum();

int main(int argc, string argv[])
{
    // vigenere requires two arguments - the second of which being the alphabetic key.
    if(argc == 2)
    {
        // as long as the key does not include a number, per the custom function:
        if(containsNum(argv[1]) == false)
        {   
            // extract key, pull phrase, create array for numeric key values
            // establish count variable
            string key = argv[1];
            string phrase = GetString();
            int numKey[strlen(key)];
            int count = 0;
            
            // set up array which converts the key into numeric values
            // a = 1, b = 2, ...
            for(int i = 0, n = strlen(key); i < n; i++)
            {
                numKey[i] = tolower(key[i]) - 'a';
            }
            
            // loop through the phrase and use the key to encrypt.
            for(int i = 0, n = strlen(phrase); i < n; i++)
            {
                // if the current letter is alphabetic
                if(isalpha(phrase[i]))
                {
                    // if the letter that would be transition TO is between 1 and 26
                    // add that value straight up, and print.
                    if(tolower(phrase[i]) - 'a' + numKey[count] < 26)
                    {
                        printf("%c",phrase[i] + numKey[count]);
                    }
                    // else, loop around the alphabet back to the beginning.
                    else
                    {
                        printf("%c",phrase[i] + numKey[count] - 26);
                    }
                    
                    // add count - the reason for this is we do NOT want to use up
                    // a letter in the key for non-alphabetic characters.
                    count = count + 1;
                    
                    // if count reaches it's max, set it back to 0 so it can start over.
                    if(count == strlen(key))
                    {
                        count = 0;
                    }
                }
                else
                {
                    // if the character is non-alphabetic, just print it.
                    printf("%c", phrase[i]);
                }
            }
        }
        else
        {
            // if the key has a number, return an error
            printf("Err\n");
            return 1;
        }
    }
    else
    {
        // if there aren't two arguments, return an error.
        printf("Err\n");
        return 1;
    }
    
    // print new line to end
    printf("\n");
}

// containsNum(string s)
// loops through all characters and checks for numbers
bool containsNum(string s)
{
    bool tracker = false;
    for(int i = 0, n = strlen(s); i < n; i++)
    {
        if(isalpha(s[i]) == false)
        {
            tracker = true;
        }
    }
    return tracker;
}
