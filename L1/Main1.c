#include <stdio.h>
#include <stdlib.h>

void main()
{
	int a[3];
	int i;
	int* p;
	p = malloc(12);
	*p = 1;
	*(p+1) = 2;
	*(p+2) = 3;
	for (i = 0; i < 3; i++)
	{
		printf("a[%d]= %d \n",i,*(p+i));
	}
	printf("\n");
	p = realloc(p, 16);
	for (i = 3; i > 0; i--)
	{
		*(p+i) = *(p+i-1);
	}
	*p = 0;
	
	for (i = 0; i < 4; i++)
	{
		printf("a[%d]= %d \n",i,*(p+i));
	}
//	printf("Hello, world!");
}