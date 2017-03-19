#include <stdio.h>
#include <stdlib.h>

void ar_print(int size, int* p)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("a[%d]= %d \n",i,*(p+i));
	}
}

int ar_ins(int pos, int num, int size, int* p)
{
	int i;
	p = realloc(p, (size*4+4));
	for (i = size; i > 0; i--)
	{
		*(p+i) = *(p+i-1);
	}
	*(p + pos) = num;
	return (size+1);
}

int ar_del(int pos, int size, int* p)
{
	int i;
	p = realloc(p, (size*4-4));
	for (i = pos; i < size; i++)
	{
		*(p+i) = *(p+i+1);
	}
	return (size-1);
}

void main()
{
    int i;
	int* p;
	int size = 3;

	p = malloc(size*4);
	for (i = 0; i < size; i++)
	{
		*(p+i) = i;
	}

	ar_print(size,p);
	printf("\n");

	size = ar_ins(0, 111, size, p);
	ar_print(size,p);
    printf("\n");

    size = ar_del(0, size, p);
	ar_print(size,p);
    printf("\n");
}
