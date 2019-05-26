#include <stdio.h>

typedef enum {false, true} bool;
bool judge(int num, int suffix);

int main(int argc, char* argv[]) {
  int M;
  scanf("%d", &M);
  
  for (int i=0; i!=M; ++i) {
    int num;
    scanf("%d", &num);
    bool success = false;
    for (int N=1; N!=10; ++N) {
      int tmp = num * num * N;
      if (!success && true == judge(tmp, num)) {
        printf("%d %d\n", N, tmp);
        success = true;
      }
    }
    if (!success) {
      printf("No\n");
    }
  }

  return 0;
}

bool judge(int num, int suffix) {
  if (num < suffix) return false;
  if (num == suffix) return true;
  while (0 != num && 0 != suffix) {
    if (num % 10 != suffix % 10) {
      return false;
    }
    num    /= 10;
    suffix /= 10;
  }
  return true;
}
