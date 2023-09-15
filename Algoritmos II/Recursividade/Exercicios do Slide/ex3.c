#include <stdio.h>

int rec(int x, int n) {
  if (n == 0)
    return 1;
  return x * rec(x, n - 1);
}

int main() {
  printf("%d\n", rec(5, 3));
  return 0;
}