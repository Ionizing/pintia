// 7-47 打印选课学生名单 （25 point(s)）

// 假设全校有最多40000名学生和最多2500门课程。现给出每个学生的选课清单，要求输出每门课的选课学生名单。

// 输入格式:
// 输入的第一行是两个正整数：N（≤40000），为全校学生总数；K（≤2500），为总课程数。此后N行，每行包括一个学生姓名（3个大写英文字母+1位数字）、一个正整数C（≤20）代表该生所选的课程门数、随后是C个课程编号。简单起见，课程从1到K编号。

// 输出格式:
// 顺序输出课程1到K的选课学生名单。格式为：对每一门课，首先在一行中输出课程编号和选课学生总数（之间用空格分隔），之后在第二行按字典序输出学生名单，每个学生名字占一行。

// 输入样例:

// 10 5
// ZOE1 2 4 5
// ANN0 3 5 2 1
// BOB5 5 3 4 2 1 5
// JOE4 1 2
// JAY9 4 1 2 5 4
// FRA8 3 4 2 5
// DON2 2 4 5
// AMY7 1 5
// KAT3 3 5 4 2
// LOR6 4 2 4 1 5
// 输出样例:

// 1 4
// ANN0
// BOB5
// JAY9
// LOR6
// 2 7
// ANN0
// BOB5
// FRA8
// JAY9
// JOE4
// KAT3
// LOR6
// 3 1
// BOB5
// 4 7
// BOB5
// DON2
// FRA8
// JAY9
// KAT3
// LOR6
// ZOE1
// 5 9
// AMY7
// ANN0
// BOB5
// DON2
// FRA8
// JAY9
// KAT3
// LOR6
// ZOE1

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// int inline hash(const std::string& str) {
  // return (str[0] - 'A') * 26 * 26 * 10\
    // + (str[1] - 'A') * 26 * 10\
    // + (str[2] - 'A') * 10\
    // + (str[3] - '0');
// }

int main(int argc, char* argv[]) {
  int nStu, nCourse;
  std::cin >> nStu >> nCourse;
  std::vector<std::vector<std::string>> Data(nCourse + 1);
  
  std::string name;
  int num;
  for (int i=0; i!=nStu; ++i) {
    std::cin >> name >> num;
    int id;
    for (int j=0; j!=num; ++j) {
      std::cin >> id;
      Data[id].push_back(name);
    }
  }

  for (int i=1; i<=nCourse; ++i) {
    std::cout << i << " " << Data[i].size() << std::endl;
    std::sort(Data[i].begin(), Data[i].end());
    for (std::string e : Data[i]) {
      std::cout << e << std::endl;
    }
  }
  return 0;
}
