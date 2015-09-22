#include <stdio.h>
#include <stdlib.h>

struct node
{
	char *word;
	struct node *next;
}

int main()
{
	char* values[] = {"apple", "banana", "cat"};
	char* h

	for(int i = 0, s = sizeof(values)/sizeof(values[0]); i < s; i++)
	{
		printf("%s\n", values[i]);
	}

}
