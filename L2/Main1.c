#include <stdio.h>
#include <stdlib.h>

void print_arr(int n, int* p)
{
	int i;
	for (i = 0; i < (n/4); i++)
	{
		printf("a[%d]= %d \n",i,*(p+i));
	}
}

int insert(int pos, int num, int n, int* p)
{
	int i;
	p = realloc(p, (n + 4));
	for (i = (n/4); i > 0; i--)
	{
		*(p+i) = *(p+i-1);
	}
	*(p + pos) = num;
	return (n + 4);
}

void main()
{
	int i;
	int* p;
	int size = 3;
	int n = size*4; //количество байт
	
	p = malloc(n);
	*p = 1;
	*(p+1) = 2;
	*(p+2) = 3;

	print_arr(n,p);
	printf("\n");
	n = insert(0, 111, n, p);
	print_arr(n,p);
}