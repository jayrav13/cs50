/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <math.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    bool result = false;
    
    // initially, I implemented a linear search algorithm per the course's spec.
    // we were later challenged to write a binary search algorithm, shown below.
    /*for(int i = 0; i < n; i++)
    {
        if(values[i] == value)
        {
            result = true;
        }
    }
    
    return result;*/
    
    // searches list of values to find the value of interest.
    
    // set pertinent variables.
    int min = 0;
    int max = n - 1;
    int loc = 0;
    bool done = false;
    
    // while not done
    while(!done)
    {
        // set location to be half way between the min and max, rounded.
        loc = round((max + min)/2);
        
        // if it's found, sweet!
        if(values[loc] == value)
        {
            result = true;
            done = true;
        }
        // if not, keep trying!
        else
        {
            // if the value we're looking for is less,
            // reset the max value
            if(value < values[loc])
            {
                max = loc - 1;
            }
            // else, reset the min value
            else
            {
                min = loc + 1;
            }
        }
        // if min is greater than max (i.e. if we've gone too far)
        // say we're done, but that we found nothing :(.
        if(min > max)
        {
            done = true;
            result = false;
        }
    } 
    
    // return the result after the "done" variable breaks us out of the while loop.
    return result;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    // set swap to a negative number to begin, 
    // initialize a temp variable
    int swap = -1;
    int temp = 0;
    
    // check if swap != 0 (i.e. something had to be switched
    // or this is the first pass
    while(swap != 0)
    {
        // set swap to 0 right away
        swap = 0;
        
        // loop through all items
        for(int i = 0; i < n - 1; i++)
        {
            // swap values if current value is greater than next value
            if(values[i] > values [i+1])
            {
                temp = values[i];
                values[i] = values[i+1];
                values[i+1] = temp;
                swap = swap + 1;
            }
        }
    }
    // yay!
    return;
}
