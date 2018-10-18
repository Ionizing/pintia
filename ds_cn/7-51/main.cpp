// 已知两个非降序链表序列S1与S2，设计函数构造出S1与S2合并后的新的非降序链表S3。

// 输入格式:
// 输入分两行，分别在每行给出由若干个正整数构成的非降序序列，用−1表示序列的结尾（−1不属于这个序列）。数字用空格间隔。

// 输出格式:
// 在一行中输出合并后新的非降序链表，数字间用空格分开，结尾不能有多余空格；若新链表为空，输出NULL。

#include <iostream>
#include <vector>

int main() {
  std::vector<int> l1, l2;
  l1.reserve(20);
  l2.reserve(20);

  int tmp;
  std::cin >> tmp;
  while (-1 != tmp) {
    l1.push_back(tmp);
    std::cin >> tmp;
  }

  std::cin >> tmp;
  while (-1 != tmp) {
    l2.push_back(tmp);
    std::cin >> tmp;
  }

  std::vector<int> res;
  res.reserve(10);
  int cur1(0), cur2(0);
  while (cur1 != l1.size() and cur2 != l2.size()) {
    if (l1[cur1] == l2[cur2]) {
      res.push_back(l1[cur1]);
      res.push_back(l1[cur1]);
      ++cur1;
      ++cur2;
    } else if (l1[cur1] < l2[cur2]) {
      res.push_back(l1[cur1]);
      ++cur1;
    } else {
      res.push_back(l2[cur2]);
      ++cur2;
    }
  }

  while (cur1 != l1.size()) {
    res.push_back(l1[cur1]);
    ++cur1;
  }

  while (cur2 != l2.size()) {
    res.push_back(l2[cur2]);
    ++cur2;
  }

  if (res.empty()) {
    std::cout << "NULL";
  }

  bool is_first(true);
  for (const auto& e : res) {
    if (is_first) {
      is_first = false;
      std::cout << e;
    } else {
      std::cout << " " << e;
    }
  }
  std::cout << std::endl;
  return 0;
}
