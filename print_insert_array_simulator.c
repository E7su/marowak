#
include < stdio.h > #include < stdlib.h >

  int pprint(int * p) {
    int i;

    printf("\n>>>   \n\n");
    for (i = 0; * (p + i) != p; i++) {
      printf("a[%d] = %d\n", i, * (p + i));
    };
    printf("\n<<<   \n");
  }

int insert(int pos, int val, int n, int * p) {
  int i;

  p = realloc(p, n + 4);
  for (i = n / 4; i > 0; i--) { * (p + i) = * (p + i - 1);
  } * (p + pos) = val;
}

void main() {
  int * p;
  int n;

  // TODO:
  // init
  // print
  // insert(ind, val)
  // print

  p = malloc(16);

  * p = 1; * (p + 1) = 2; * (p + 2) = 3; * (p + 3) = p;

  pprint(p);

  n = 16;
  insert(0, 12345, n, p);
  pprint(p);
}

/*	
	printf(">>>   \n\n");

	for (i=0; i < 3; i++)
	{
	printf("a[%d] = %d\n", i, *(p + i));
	}

	p = realloc(p, 16);
	for (i=3; i > 0; i--)
	{
	*(p + i) = *(p + i - 1);
	//printf("a[%d] = %d\n", i, *(p + i));
	}
	*p =0;
	printf("\n<<<   \n");	
	
	for (i=0; i < 4; i++)
	{
	printf("a[%d] = %d\n", i, *(p + i));
	}
*/
//printf("I don't like ';' !!!\n");
