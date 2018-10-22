#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int inline hash(const std::string& str) {
  return (str[0] - 'A') * 26 * 26 * 10\
    + (str[1] - 'A') * 26 * 10\
    + (str[2] - 'A') * 10\
    + (str[3] - '0');
}

int main(int argc, char* argv[]) {
  int nQuery, nCourse;
  std::cin >> nQuery >> nCourse;
  
  std::vector<std::vector<int>> Data;
  Data.resize(26 * 26 * 26 * 10);

  int course_id, stu_num;
  std::string name;
  // int tmp;
  for (int i=0; i!=nCourse; ++i) {
    std::cin >> course_id >> stu_num;
    int id = hash(name);
    for (int j=0; j!=stu_num; ++j) {
      std::cin >> name;
      Data[id].push_back(course_id);
    }
  }

  for (int i=0; i!=nQuery; ++i) {
    std::cin >> name;
    int id = hash(name);
    std::cout << name << " " << Data[id].size();
    std::sort(Data[id].begin(), Data[id].end());
    for (auto e : Data[id]) {
      std::cout << " " << e;
    } std::cout << std::endl;
  }
}
