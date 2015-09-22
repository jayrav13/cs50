#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* x;
	int* y;

	x = malloc(sizeof(int));

	*x = 42;
	*y = 13;

	y = x;

	*y = 13;

	printf("x is %d and y is %d\n", *x, *y);
}
