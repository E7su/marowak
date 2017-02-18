#include <stdio.h>
#include <stdlib.h>

void main() {
	int a[3];
	int* p;
	int i;
	
	p = malloc(12);
	*p = 1;
	*(p + 1) = 2;
	*(p + 2) = 3;
	
	printf(">>>   \n\n");

	for (i=0; i < 3; i++)
	{
	printf("a[%d] = %d\n", i, *(p + i));
	}

	p = realloc(p, 16);
	for (i=3; i > 0; i--)
	{
	*(p + i) = *(p + i - 1);
	}
	*p =0;
	printf("\n<<<   \n");	
	
	for (i=0; i < 4; i++)
	{
	printf("a[%d] = %d\n", i, *(p + i));
	}
	
	printf("I don't like ';' !!!\n");
}
