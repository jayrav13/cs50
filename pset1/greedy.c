#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // set variables
    int money = -1;
    int coins = 0;
    int types[4] = {25,10,5,1};
    
    // money was set to -1 so that the program can keep asking for 
    // an input until it is valid.
    while (money < 0)
    {
        printf("How much change is owed?\n");
        money = round(GetFloat() * 100);
    }
    
    // subtract each coin type, starting from the largest, until
    // all change has been returned.
    for (int x = 0; x < 4; x++)
    {
        while(money >= types[x])
        {
            money = money - types[x];
            coins = coins + 1;
        }
    }
    
    // print number of coins returned.
    printf("%i\n",coins);
}
