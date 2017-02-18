#include <stdio.h>
#include <stdlib.h>

void main() {
	int a[3];
	int* p;
	int i;
	
	p = malloc(12);
	*p = 0;
	*(p + 1) = 1;
	*(p + 2) = 2;
	
	printf(">>>   \n\n");

	for (i=0; i < 3; i++)
	{
	printf("a[%d] = %d\n", i, *(p + i));
	}

	printf("\n<<<   \n");	
	printf("I don't like ';' !!!\n");
}
