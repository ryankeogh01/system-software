#include <stdio.h>

void myFun(int *x) {
  *x = *x * 2;
}

int main(void) {
  int y = 50;
  printf("y=%d\n", y);
  myFun(&y);
  printf("y=%d\n", y);
  return 0;
}