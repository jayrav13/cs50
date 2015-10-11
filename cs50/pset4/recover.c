/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
 
// include libraries
#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int counter = 0;                        // keeps track of number of jpg's found
    const int BLOCK_SIZE = 512;             // block size by which we're searching
    char fileName[8];                       // name of output file
    
    FILE* file = fopen("card.raw","r");     // input file
    FILE* output = NULL;                    // output file variable
    
    uint8_t buffer[BLOCK_SIZE];             // buffer variable

    int firstFileFound = 0;                 // file found variable

    // while there are still more data blocks available
    while(fread(&buffer, BLOCK_SIZE, 1, file))
    {
        // if the buffer fits the specific .jpg pattern
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
        {
            // if there is an open file, close it
            if(output != NULL)
            {
                fclose(output);
            }
            
            // create a new file with file name = to the counter value
            sprintf(fileName, "%03i.jpg", counter);
            // open the file as a writable file
            output = fopen(fileName, "w");
            // increment the counter
            counter = counter + 1;
            //set the file found variable to 1
            firstFileFound = 1;
        }
        // if the file has been found, write it to the current file
        // this is used because there are a lot of bits at the beginning
        // of the file that needs to be ignored. the firstFile Found
        // variable waits until at least the first block is found
        if(firstFileFound)
        {
            fwrite(&buffer, BLOCK_SIZE, 1, output);
        }
    }
    fclose(output);
    fclose(file);
}
