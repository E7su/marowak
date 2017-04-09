#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int count = 3;
int* p;

void ar_print(int* p)
{
	int i;
	for (i = 0; i < count; i++)
	{
		printf("a[%d]= %d \n",i,*(p+i));
	}
}

void ar_ins(int pos, int num, int* p)
{
	int i;
/*	if (count == cap)
	{
		cap += abs(count/2);
		p = realloc(p, (cap*4));
	}*/
	count++;
	p = realloc(p, count*4);
	for (i = count-1; i >= pos; i--)
	{
		*(p+i) = *(p+i-1);
	}
	*(p + pos) = num;
}

int ar_del(int pos, int* p)
{
	int i;
	int tmp;
	tmp = *(p + pos);
	for (i = pos; i <= count; i++)
	{
		*(p+i) = *(p+i+1);
	}
/*	if (cap == (2*count))
	{
		p = realloc(p, ((cap-count)/2));
	}*/
	count--;
	p = realloc(p, count*4);
	return tmp;
}

int ar_get(int pos, int* p)
{
	return (*(p + pos));
}

void ar_replace(int pos1, int pos2, int* p)
{
	int tmp;
	tmp = ar_del(pos1, p);
	ar_ins(pos1, (ar_del(pos2-1, p)), p);
	ar_ins(pos2, tmp, p);
}

void ar_sort(int* p)
{
	int i,j;
	for(i=0;i<=count;i++)
		{
			for(j=0;j<=count;j++)
				{
					if ((ar_get(j,p)) > (ar_get(j+1,p)))
						ar_replace(j,j+1,p);					
				}
		}
}

int random1(int m)
{
	srand(time(NULL));
	return rand()%m;
}

void main()
{
    int i;
	int tmp;
	int cap = 3;
	int get;
	
	int a,b;

	p = malloc(count*4);
	for (i = 0; i < count; i++)
	{
		*(p+i) = i;
	}

	ar_print(p);
	printf("\n");

	ar_ins(0, 111, p);
	ar_print(p);
    printf("\n");

    tmp =  ar_del(0, p);
	ar_print(p);
	printf("\n");

	ar_replace(0, 2, p);
	ar_print(p);
	printf("\n");	
	
	ar_ins(count, random1(10), p);
	ar_print(p);
    printf("\n");
	
	
	ar_sort(p);
	ar_print(p);
	
}
