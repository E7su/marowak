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

void ar_ins(int pos, int num, int count, int cap, int* p)
{
	int i;
	if (count == cap)
	{
		cap += abs(count/2);
		p = realloc(p, (cap*4));
	}
	for (i = count; i > 0; i--)
	{
		*(p+i+pos) = *(p+i+pos-1);
	}
	*(p + pos) = num;
	count++;
}

int ar_del(int pos, int count, int cap, int* p)
{
	int i;
	int tmp;
	tmp = *(p + pos);
	for (i = pos; i < count; i++)
	{
		*(p+i) = *(p+i+1);
	}
	if (cap == (2*count))
	{
		p = realloc(p, ((cap-count)/2));
	}
	count--;
	return tmp;
}

int ar_get(int pos, int* p)
{
	return (*(p + pos));
}

void ar_replace(int pos1, int pos2, int count, int cap, int* p)
{
	int tmp;
	tmp = ar_del(pos1, count, cap, p);
	ar_ins(pos1, (ar_get(pos2-1, p)), count, cap, p);
	ar_print(count,p);
	printf("\n");
	//*(p + pos2) = tmp;
	ar_ins(pos2, tmp, count, cap, p);
}

int count = 3;

void main()
{
    int i;
	int* p;
	int tmp;
	int cap = 3;
	int get;

	p = malloc(count*4);
	for (i = 0; i < count; i++)
	{
		*(p+i) = i;
	}

	ar_print(count,p);
	printf("\n");

	ar_ins(0, 111, count, cap, p);
	ar_print(count,p);
    printf("\n");

    tmp =  ar_del(0, count, cap, p);
	ar_print(count,p);
	printf("\n");

	get = ar_get(0, p);
	printf("\n");

	ar_replace(0, 2, count, cap, p);
	ar_print(count,p);
}
