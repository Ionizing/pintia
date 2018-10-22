// 7-49 打印学生选课清单 （25 point(s)）

// 假设全校有最多40000名学生和最多2500门课程。现给出每门课的
// 选课学生名单，要求输出每个前来查询的学生的选课清单。

// 输入格式:
// 输入的第一行是两个正整数：N（≤40000），为前来查询课表的学
// 生总数；K（≤2500），为总课程数。此后顺序给出课程1到K的选课
// 学生名单。格式为：对每一门课，首先在一行中输出课程编号（简
// 单起见，课程从1到K编号）和选课学生总数（之间用空格分隔），
// 之后在第二行给出学生名单，相邻两个学生名字用1个空格分隔。
// 学生姓名由3个大写英文字母+1位数字组成。选课信息之后，在一
// 行内给出了N个前来查询课表的学生的名字，相邻两个学生名字用1个空格分隔。

// 输出格式:
// 对每位前来查询课表的学生，首先输出其名字，随后在同一行中输
// 出一个正整数C，代表该生所选的课程门数，随后按递增顺序输出
// C个课程的编号。相邻数据用1个空格分隔，注意行末不能输出多余空格。

// 输入样例:

// 10 5
// 1 4
// ANN0 BOB5 JAY9 LOR6
// 2 7
// ANN0 BOB5 FRA8 JAY9 JOE4 KAT3 LOR6
// 3 1
// BOB5
// 4 7
// BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
// 5 9
// AMY7 ANN0 BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
// ZOE1 ANN0 BOB5 JOE4 JAY9 FRA8 DON2 AMY7 KAT3 LOR6
// 输出样例:

// ZOE1 2 4 5
// ANN0 3 1 2 5
// BOB5 5 1 2 3 4 5
// JOE4 1 2
// JAY9 4 1 2 4 5
// FRA8 3 2 4 5
// DON2 2 4 5
// AMY7 1 5
// KAT3 3 2 4 5
// LOR6 4 1 2 4 5


#include <iostream>
#include <string>
#include <unordered_map>
#include <set>

int main(int argc, char* argv[]) {
  int nQuery, nCourse;
  std::cin >> nQuery >> nCourse;
  
  std::unordered_map<std::string, std::set<int>> Data;
  int course_id, stu_num;
  std::string name;
  // int tmp;
  for (int i=0; i!=nCourse; ++i) {
    std::cin >> course_id >> stu_num;
    for (int j=0; j!=stu_num; ++j) {
      std::cin >> name;
      Data[name].insert(course_id);
    }
  }

  for (int i=0; i!=nQuery; ++i) {
    std::cin >> name;
    std::cout << name << " " << Data[name].size();
    for (auto e : Data[name]) {
      std::cout << " " << e;
    } std::cout << std::endl;
  }
}
