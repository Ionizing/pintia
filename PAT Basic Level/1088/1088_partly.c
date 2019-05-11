#include <stdio.h>

inline int abs(int n) { return n < 0 ? -n : n; }

int main(int argc, char* argv[]) {
  int self, X, Y;
  scanf("%d%d%d", &self, &X, &Y);

  int threePeople[3] = {0};
  int A = 0, B = 0, C = 0;
  for (int i = 9; i != 0; --i) {
    for (int j = 9; j != -1; --j) {
      if (9 * abs(i - j) * Y == 30 * j + 3 * i) {
        A = 10 * i + j;
        B = 10 * j + i;
        C = B / Y;
        threePeople[0] = (self > A) - (self < A);
        threePeople[1] = (self > B) - (self < B);
        threePeople[2] = (self > C) - (self < C);
        /* printf("******** %d %d %d\n", A, B, C); */
        goto outer;
      }
    }
  }

  outer:

  if (0 == A) {
    puts("No Solution");
    return 0;
  }

  /* printf("%d %d %d\n", A, B, C); */
  printf("%d", A);
  for (int i=0; i!=3; ++i) {
    switch (threePeople[i]) {
      case -1: printf(" Cong"); break;
      case  0: printf(" Ping"); break;
      case  1: printf(" Gai"); break;
    }
  }
  return 0;
}
