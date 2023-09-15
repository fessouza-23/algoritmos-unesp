#include <stdio.h>

void rec(int n) {
  if (n == 1) {
    printf("1");
    return;
  }
  rec(n - 1);
  printf(" %d ", n);
  rec(n - 1);
}

int main() {
  rec(5);
  return 0;
}