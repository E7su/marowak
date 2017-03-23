#include < time.h > 
#include < stdio.h > 
#include < stdlib.h >

int size = 4;
int * p;

void insrt(int val, int pos) {
  int i;
  size++;
  p = realloc(p, size * 4);
  for (i = size - 1; i >= pos; i--) { 
  * (p + i) = * (p + i - 1);
  } 
  * (p + pos) = val;
}

void print(int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("a[%d]  = %d\n", i, * (p + i));
  }
  printf("\n");
}

int del(int pos) {
  int i, tmp, dl;
  dl = * (p + pos);

  for (i = pos; i <= size; i++) {
    tmp = * (p + i + 1); 
    * (p + i) = tmp; 
    * (p + i + 1) = tmp;
  }
  size -= 1;
  p = realloc(p, size * 4);
  return dl;
}

int getelem(int pos) {
  return *(p + pos);
}

void replace(int A, int B) {
  int tmp;
  tmp = del(A);
  insrt(del((B - 1)), A);
  insrt(tmp, B);
}

void sort() {
  int i, j;
  for (i = 0; i <= size; i++) {
    for (j = size - 1; j > i; j--) {
      if (getelem(j - 1) > getelem(j)) {
        replace(j - 1, j);
      }
    };
  }
}

void randint(int num) {
  int i, pos, val;
  srand(time(NULL));

  for (i = 0; i <= num; i++) {
    pos = rand() % size;
    val = rand() % 150;
    insrt(val, pos);
  }
}

void main() {
  int i, val, pos, elem, delem;

  p = malloc(size * 4); 
  * p = 1; 
  * (p + 1) = 2; 
  * (p + 2) = 3; 
  * (p + 3) = 4;

  print(size);
  randint(10);
  print(size);

  /*
  insrt(-3, 4, p);
  insrt(220, 4, p);
  */

  print(size);
  elem = del(1);
  printf("%d\n", elem);

  print(size);
  delem = getelem(2);

  printf("\n%d\n", delem);
  replace(1, 3);
  print(size);

  sort();
  print(size);
}
