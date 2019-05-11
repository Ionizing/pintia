#include <stdio.h>

int main(int argc, char* argv[]) {
  int table[1<<20] = {0};
  int N;
  int cnt = 0;
  scanf("%d", &N);
  for (int i=0; i!=N+1; ++i) {
    int result = i / 2 + i / 3 + i / 5;
    if (0 == table[result]) {
      ++table[result];
      ++cnt;
    }
  }

  printf("%d", cnt);
  return 0;
}
