#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b);

int main()
{
	int x = 1;
	int y = 2;
	
	printf("The value of x is %d\n", x);
	printf("The value of y is %d\n", y);
	printf("Swapping...\n");
	swap(&x, &y);
	printf("Swapped!\n");
	printf("The value of x is %d\n", x);
	printf("The value of y is %d\n", y);
}

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;	
}
