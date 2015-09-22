#include <stdio.h>
#include <stdlib.h>

void search(int n);
void insert(int n);

// create typedef
typedef struct node
{
	int n;
	struct node* next;
} 
node;

// declare global linked list (for now, not typical)
node* first = NULL;

int main()
{
	insert(4);
}

void search(int n)
{
	node* ptr = first;
	while(ptr != NULL)
	{
		// ptr->n is the same as (*ptr).n
		if(ptr->n == n)
		{
			// announce that we've found the value.
			break;
		}
		else
		{
			ptr = ptr->next;
		}
	}
}

void insert(int n)
{
	node* newNode = malloc(sizeof(node));

	if(newNode == NULL)
	{
		return;
	}
	
	if(first == NULL)
	{
		first = newNode;
		newNode->n = n;
		newNode->next = NULL;
		printf("Inserted %d at the head of the list.\n", first->n);
	}
	
	
	
}
