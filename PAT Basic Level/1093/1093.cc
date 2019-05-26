#include <iostream>
#include <string>

bool charset[1<<9] = {false};

int main(int argc, char* argv[]) {
  std::string A, B;
  std::getline(std::cin, A);
  std::getline(std::cin, B);

  for (char ch : A) {
    if (false == charset[ch]) {
      std::cout << ch;
      charset[ch] = true;
    }
  }

  for (char ch : B) {
    if (false == charset[ch]) {
      std::cout << ch;
      charset[ch] = true;
    }
  }
  return 0;
}
