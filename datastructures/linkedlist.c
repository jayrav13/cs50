// declare includes statements
#include <stdio.h>
#include <stdlib.h>

// define node as containing an integer and next node
struct node {
	int x;
	struct node *next;
};

// define prototypes for methods
void scan(struct node *node);
void add(int val, struct node *node);
int search(int val, struct node *node);
void clear(struct node *node);
void push(int val, struct node **node);
struct node *pop(struct node **node);

// main
int main()
{
	// set up head node
	struct node *head = (struct node*) malloc(sizeof(struct node));
	head->x = 3;

	// set up next node
	struct node *next = (struct node*) malloc(sizeof(struct node));
	next->x = 5;
	next->next = NULL;

	// point head to next
	head->next = next;

	// scan over linked list
	scan(head);

	// add a few values...
	add(20, head);
	add(25, head);
	add(32, head);
	
	// scan to confirm they've been added
	scan(head);

	// is 42 a part of the list?
	printf("Searching for 42. Search status: %d\n", search(42, head));

	push(-2, &head);	
	push(4, &head);

	scan(head);

	// clear the list.
	clear(head);

}

void scan(struct node *node) {
	struct node *current = node;

	printf("Scanning...\n"); 
	
	while(current != NULL) {
		printf("%d ... ", current->x);
		current = current->next;
	}	

	printf("Scan complete.\n");

}

void add(int val, struct node *node) {

	struct node *current = node;

	while(current->next != NULL) {
		current = current->next;
	}

	struct node *added = (struct node*) malloc(sizeof(struct node));
	added->x = val;
	added->next = NULL;
	current->next = added;

	printf("Added %d\n", added->x);

}

int search(int val, struct node *node) {
	struct node *current = node;	
	int found = 0;

	while(current != NULL) {
		if(current->x == val) {
			found = 1;
			break;
		}
		
		current = current->next;
	}

	return found;
}

void clear(struct node *node) {
		
	struct node *current = node;
	struct node *next;

	while(current != NULL) {
		next = current->next;
		printf("Clearing: %d\n", current->x);
		free(current);
		current = next;
	}
}

void push(int val, struct node **node) {
	struct node *new = (struct node*) malloc(sizeof(struct node));

	new->next = *node;
	new->x = val;
	*node = new;

	printf("Pushed %d onto the stack\n", new->x);
}


