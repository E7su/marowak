#include <stdio.h>
#include <stdlib.h>

void main()
{
	int a = 10, b = 11, c;
	printf("%d %d \n",a,b);
	c = a;
	a = b;
	b = c;	
	printf("%d %d \n",a,b);
	printf("============ \n");
	a = 10;
	b = 11;
	printf("%d %d \n",a,b);
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("%d %d \n",a,b);
}