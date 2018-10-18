// 已知两个非降序链表序列S1与S2，设计函数构造出S1与S2的交集新链表S3。

#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
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
  for (int cur1=0, cur2=0; cur1!=l1.size() and cur2 !=l2.size();) {
    if (l1[cur1] == l2[cur2]) {
      res.push_back(l1[cur1]);
      ++cur1;
      ++cur2;
    } else if (l1[cur1] < l2[cur2]) {
      ++cur1;
    } else {
      ++cur2;
    }
  }
  if (res.empty()) {
    std::cout << "NULL" << std::endl;
    return 0;
  }

  bool is_first = true;
  for (int i=0; i!=res.size(); ++i) {
    if (is_first) {
      is_first = false;
      std::cout << res[i];
    } else {
      std::cout << " " << res[i];
    }
  }
  return 0;
}
