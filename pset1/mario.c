#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // initialize height
    int height = -1;
    
    // while the height value hasn't been set to a valid value
    while(height < 0 || height > 23)
    {
        printf("Enter a height: ");
        height = GetInt();
    }
    
    // loop through all values for height
    for (int x = 0; x < height; x++)
    {
        // move from 0 to the current iteration for height
        for (int y = 0; y < height + 1; y++)
        {
            // the mario "stair case" works by adding # to each
            // row, where the number of # per row is the same as 
            // the "number-th" row we're on at the right-most side.
            // add spaces until ready to add a #.
            if (y < height - x - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        
        // move to new line and start again!
        printf("\n");
    }
    
    

}
