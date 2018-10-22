#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int inline hash(const std::string &str) {
  return (str[0] - 'A') * 26 * 26 * 10 + (str[1] - 'A') * 26 * 10 +
         (str[2] - 'A') * 10 + (str[3] - '0');
}

void print_id(int id) {
  putchar(id / (26 * 26 * 10) + 'A');
  id %= 26 * 26 * 10;
  putchar(id / (26 * 10) + 'A');
  id %= 26 * 10;
  putchar(id / (10) + 'A');
  id %= 10;
  putchar(id + '0');
}

int main(int argc, char *argv[]) {
  int nStu, nCourse;
  std::cin >> nStu >> nCourse;
  std::vector<std::vector<int>> Data(nCourse + 1);

  std::string name;
  int num;
  for (int i = 0; i != nStu; ++i) {
    std::cin >> name >> num;
    int id;
    for (int j = 0; j != num; ++j) {
      std::cin >> id;
      Data[id].push_back(hash(name));
    }
  }

  for (int i = 1; i <= nCourse; ++i) {
    std::cout << i << " " << Data[i].size() << std::endl;
    std::sort(Data[i].begin(), Data[i].end());
    for (int e : Data[i]) {
      print_id(e); putchar('\n');
    }
  }
  return 0;
}
