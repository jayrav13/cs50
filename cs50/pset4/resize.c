/**
 * resize.c
 *
 * Jay Ravaliya
 * Problem Set 4
 *
 * Implemented based on copy.c by CS50 staff
 *
 * Copies a BMP piece by piece to resize using padding.
 */
       
#include <stdio.h>
#include <stdlib.h>
 
#include "bmp.h"
 
int main(int argc, char* argv[])
{
    
    // ensure proper usage
    if (argc != 4 || atoi(argv[1]) > 100 || atoi(argv[1]) <= 0)
    {
        printf("Usage: ./resize (n<=100) infile outfile\n");
        return 1;
    }
 
    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];
 
    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }
 
    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }
 
    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
 
    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
 
    // calculate padding per dimensions
    int inputPadding =  (4 - ((bi.biWidth * sizeof(RGBTRIPLE)) % 4)) % 4;
    int outputPadding =  (4 - ((bi.biWidth * atoi(argv[1]) * sizeof(RGBTRIPLE)) % 4)) % 4;
 
    // printf("Input Padding: %i, Output Padding: %i\n", inputPadding, outputPadding);
 
    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
 
    // reset header values for writing to output file
    bi.biHeight = bi.biHeight * atoi(argv[1]);
    bi.biWidth = bi.biWidth * atoi(argv[1]);
    bi.biSizeImage = (bi.biWidth * sizeof(RGBTRIPLE) + outputPadding) * abs(bi.biHeight);
    bf.bfSize = bi.biSizeImage + 54;
 
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
 
    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);
 
    // create data structure for triples
    RGBTRIPLE trip[abs(bi.biWidth)/atoi(argv[1])];
    
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight/atoi(argv[1])); i < biHeight; i++)
    {
        // iterate over row
        for (int j = 0, biWidth = bi.biWidth/atoi(argv[1]); j < biWidth; j++)
        {
            fread(&trip[j], sizeof(RGBTRIPLE), 1, inptr);
        }
        
        // skip over padding, if any
        fseek(inptr, inputPadding, SEEK_CUR);
        for (int a = 0; a < atoi(argv[1]); a++)
        {
            for (int k = 0, biWidth = bi.biWidth/atoi(argv[1]); k < biWidth; k++)
            {
                for (int l = 0; l < atoi(argv[1]); l++)
                {
                    fwrite(&trip[k], sizeof(RGBTRIPLE), 1, outptr);
                } 
            }
            for (int k = 0; k < outputPadding; k++)
            {
                fputc(0x00, outptr);
            }
        }
    }
    // close infile
    fclose(inptr);
 
    // close outfile
    fclose(outptr);
 
    // that's all folks
    return 0;
}
