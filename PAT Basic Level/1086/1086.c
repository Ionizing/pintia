#include <stdio.h>

int main(int argc, char* argv[]) {
  int a, b;
  scanf("%d%d", &a, &b);
  int c = a * b;
  while (0 != c && c % 10 == 0) {
    c /= 10;
  }

  do {
    putchar('0' + c % 10);
    c /= 10;
  } while (c != 0);
  return 0;
}
