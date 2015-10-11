// include statements
#include <stdio.h>
#include <stdlib.h>

// setting up my node struct
typedef struct node
{
	int n;
	struct node* next;
} node;

// declaring upcoming functions
void add(int n, struct node* head);
void traverse(struct node* head);
int counter(struct node* head);
int search(struct node* head, int n);
void delete(struct node* head, int n);

// main
int main(int argc, char* argv[])
{
	struct node* head = malloc(sizeof(node));
	head->next = NULL;

	for(int i = 1; i <= 10; i++)
	{
		add(i, head);
	}

	traverse(head);

	int count = counter(head);
	printf("Count: %d\n", count);

	int query = 22;
	int found = search(head, query);
	if(found)
	{
		printf("Found %d in linked list.\n", query); 
	}
	else
	{
		printf("Did not find %d in linked list.\n", query);
	}

	delete(head, 7);
	delete(head, 1);
	delete(head, 10);
	traverse(head);
}

// add to end of linked list
void add(int n, struct node* head)
{

	struct node* new = malloc(sizeof(node));
	new->n = n;
	new->next = NULL;

	struct node* ptr = head;

	while(ptr->next != NULL)
	{
		ptr = ptr->next;
	}

	ptr->next = new;
	printf("Added %d.\n", n);

}

// print out all items in the linked list
void traverse(struct node* head)
{
	struct node* ptr = head;
	while(ptr->next != NULL)
	{
		printf("%d\n", ptr->next->n);
		ptr = ptr->next;
	}
}

// return number of items in the linked list
int counter(struct node* head)
{
	struct node* ptr = head;
	int count = 0;
	while(ptr->next != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	return count;
}

// return 1 if item exists in list, else returns 0
int search(struct node* head, int n)
{
	struct node* ptr = head;
	int found = 0;
	while(ptr->next != NULL)
	{
		if(ptr->next->n == n)
		{
			found = 1;
			break;
		}
		ptr = ptr->next;
	}
	return found;
}

// delete a node from the linked list.
void delete(struct node* head, int n)
{
	struct node* prev = head;
	struct node* next = head->next;

	while(next != NULL)
	{
		if(next->n == n)
		{
			prev->next = next->next;
			free(next);	
			break;
		}
		else
		{
			prev = next;
			next = next->next;
		}
	}
}
