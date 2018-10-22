// 输入格式:

// 输入的第一行包含两个正整数N(≤10
// ​5
// ​​ ) 和C，其中N是纪录的条数，C是指定排序的列号。之后有 N行，每行包含一条学生纪录。每条学生纪录由学号（6位数字，保证没有重复的学号）、姓名（不超过8位且不包含空格的字符串）、成绩（[0, 100]内的整数）组成，相邻属性用1个空格隔开。

// 输出格式:

// 在N行中输出按要求排序后的结果，即：当C=1时，按学号递增排序；当C=2时，按姓名的非递减字典序排序；当C=3时，按成绩的非递减排序。当若干学生具有相同姓名或者相同成绩时，则按他们的学号递增排序。

// 输入样例:

// 3 1
// 000007 James 85
// 000010 Amy 90
// 000001 Zoe 60
// 输出样例:

// 000001 Zoe 60
// 000007 James 85
// 000010 Amy 90

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <tuple>

int main(int argc, char* argv[]) {
  int N, C;
  std::cin >> N >> C;
  using ttype = std::tuple<int, std::string, int>;
  // ID, name, score
  std::vector<ttype> Data;

  int id, score;
  std::string name;
  for (int i=0; i!=N; ++i) {
    std::cin >> id >> name >> score;
    Data.push_back(ttype(id, name, score));
  }

  auto less = [C](ttype& a, ttype& b) {
    switch(C) {
      case 1 : return std::get<0>(a) < std::get<0>(b);
      case 2 : return std::get<1>(a) != std::get<1>(b) ?
                 std::get<1>(a) < std::get<1>(b):
                 std::get<0>(a) < std::get<0>(b) ;
      case 3 : return std::get<2>(a) != std::get<2>(b) ? 
                 std::get<2>(a) < std::get<2>(b):
                 std::get<0>(a) < std::get<0>(b) ;
    }
  };

  std::sort(Data.begin(), Data.end(), less);
  for (const auto& e : Data) {
    printf("%06d %s %d\n", std::get<0>(e), std::get<1>(e).c_str(), std::get<2>(e));
  }
  return 0;
}
