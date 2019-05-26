#include <cmath>
#include <iostream>
#include <string>

bool isPrime(const int n);

int main(int argc, char* argv[]) {
  int L, K;
  std::string line;
  std::cin >> L >> K;
  std::cin >> line;

  bool isFound = false;
  for (int i = 0; i != L - K + 1; ++i) {
    std::string tmpstr{line.begin() + i, line.begin() + i + K};
    int num = std::atoi(tmpstr.c_str());
    if (!isFound and isPrime(num)) {
      std::cout << tmpstr;
      isFound = true;
    }
  }
  if (!isFound) {
    std::cout << 404;
  }
  return 0;
}

bool isPrime(const int n) {
  if (2 == n) return true;
  for (int i = 2; i <= std::sqrt(n); i++) {
    if (n % i == 0) return false;
  }

  return true;
}
