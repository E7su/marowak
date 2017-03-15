#include <stdio.h>
#include <stdlib.h>

int size = 4;
int* p;


void insrt(int val,  int pos,  int* p)
{
	int i;
	size++;
	p  =  realloc(p,  size * 4);
	for(i = size - 1; i >=  pos; i--)
	{
		*(p + i) = *(p + i - 1);
	}
	*(p + pos) = val;
}


void print(int size, int* p)
{
	int i;
		for (i = 0; i<size; i++ )
	{
			printf("a[%d]  = %d\n", i, *(p + i));
	}
	printf("\n");
}


int del(int pos, int* p)
{
	int i, tmp, dl;
	dl = *(p + pos);
	
	for(i = pos; i <= size; i++)
	{
		tmp = *(p + i + 1);
		*(p + i) = tmp;
		*(p + i + 1) = tmp;
	}
	size -= 1;
	p = realloc(p, size*4);
	return dl;
}


int getelem (int pos, int* p)
{
	return *(p + pos);

}


void replace(int A, int B)
{
	int tmp;
	tmp = del(A, p);
	insrt(del((B - 1), p), A, p);
	insrt(tmp, B, p);
}


void main()
{	
	int i, val, pos, elem, delem;
	
	p = malloc(size * 4);
	*p = 1;
	*(p + 1) = 2;
	*(p + 2) = 3;
	*(p + 3) = 4;
	
	print(size, p);
	insrt(19, 2, p);
	
	print(size, p);
	elem = del(1, p);
	printf("%d\n",  elem);
	
	print(size, p);
	delem = getelem(2, p);
	
	printf("\n%d\n", delem);
	replace(1, 3);
	print(size, p);

	/*p = realloc(p, 16);
	for (i = 3; i>0; i--)
	{
		*(p + i) = *(p + i-1);
	}
	*p = 21;
	printf("\n");
	for (i = 0; i<4; i +  + )
	{
			printf("a[%d]  = %d\n", i, *(p + i));
	}*/
}
