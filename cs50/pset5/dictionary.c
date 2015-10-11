/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

#include "dictionary.h"

#define MAX_LENGTH 47

// establish typedef struct node
typedef struct node
{
    char word[MAX_LENGTH];
    struct node* next;
}
node;

int dictionarySize = 0;
node* head;
node* currentNode;
node* crawler;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* thisWord)
{
    crawler = malloc(sizeof(node));
    crawler->next = head->next;
    strcpy(crawler->word, head->word);
    
    bool returnValue = false;
    char newWord[strlen(thisWord) + 1];
    strcpy(newWord, thisWord);
    
    for(int i = 0, s = strlen(newWord); i < s; i++)
    {
      newWord[i] = tolower(newWord[i]);
    }
    
    strcat(newWord, "\n");
    
    while(crawler != NULL)
    {
        if(strcmp(newWord, crawler->word) == 0)
        {
            returnValue = true;
        }
        
        crawler = crawler->next;
    }
    
    free(crawler);
    return returnValue;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // open file, set temp string, set size variable
    FILE* file = fopen(dictionary, "r");
    
    if(file == NULL)
    {
        return false;
    }
    
    char currentWord[MAX_LENGTH];
    head = malloc(sizeof(node));
    
    // continue infinite loop
    while(true)
    {   
        fgets(currentWord, MAX_LENGTH, file);
        
        if(feof(file))
        {
            break;
        }
        
        // if first, set head node
        if(size == 0)
        {
            strcpy(head->word, currentWord);
            head->next = NULL;
        }
        // else point node to head, reset
        else
        {
            currentNode = malloc(sizeof(node));
            strcpy(currentNode->word, currentWord);
            currentNode->next = head;
            head = currentNode;
        }
        
        // increment size
        dictionarySize++;
    }
    
    fclose(file);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return dictionarySize;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    return true;
}
