#include <iostream>

int CakeSales[1000] = {0};

int main(int argc, char* argv[]) {
  int N, M;
  std::cin >> N >> M;

  for (int i=0; i!=M; ++i) {
    for (int j=0; j!=N; ++j) {
      int tmp;
      std::cin >> tmp;
      CakeSales[j] += tmp;
    }
  }

  int MaxVal = -1;
  for (int i=0; i!=N; ++i) {
    MaxVal = (MaxVal > CakeSales[i]) ? MaxVal : CakeSales[i];
  }
  std::cout << MaxVal << std::endl;

  bool isFirst = true;
  for (int i=0; i!=N; ++i) {
    if (MaxVal == CakeSales[i]) {
      if (isFirst) {
        isFirst = false;
        std::cout << i + 1;
      } else {
        std::cout << " " << i + 1;
      }
    }
  }
  return 0;
}
