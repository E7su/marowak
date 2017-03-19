#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ar_print(int count, int* p)
{
	int i;
	for (i = 0; i < count; i++)
	{
		printf("a[%d]= %d \n",i,*(p+i));
	}
}

int ar_ins(int pos, int num, int count, int cap, int* p)
{
	int i;
	if (count == cap)
	{
		cap += abs(count/2);
		p = realloc(p, (cap*4));
	}
	for (i = count; i > 0; i--)
	{
		*(p+i) = *(p+i-1);
	}
	*(p + pos) = num;
	return (count+1);
}

int ar_del(int pos, int count, int cap, int* p)
{
	int i;
	for (i = pos; i < count; i++)
	{
		*(p+i) = *(p+i+1);
	}
	if (cap == (2*count))
	{
		p = realloc(p, ((cap-count)/2));
	}
	return (count-1);
}

void main()
{
    int i;
	int* p;
	int count = 3;
	int cap = 3;

	p = malloc(count*4);
	for (i = 0; i < count; i++)
	{
		*(p+i) = i;
	}

	ar_print(count,p);
	printf("\n");

	count = ar_ins(0, 111, count, cap, p);
	ar_print(count,p);
    printf("\n");

    count = ar_del(0, count, cap, p);
	ar_print(count,p);
    printf("\n");
}
