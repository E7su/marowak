#include <stdio.h>

void main()
{
	int a[3];
	int i;
	int* p;
	a[0] = 0;
	a[1] = 1;
	a[2] = 2;
	p = &a[0];
	for (i = 0; i < 3; i++)
	{
		printf("0x%x %d \n",p,*p);
		p++;
	}
//	printf("Hello, world!");
}