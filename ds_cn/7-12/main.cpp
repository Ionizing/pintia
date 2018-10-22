// 给定N个（长整型范围内的）整数，要求输出从小到大排序后的结果。

// 本题旨在测试各种不同的排序算法在各种数据情况下的表现。各组测试数据特点如下：

// 数据1：只有1个元素；
// 数据2：11个不相同的整数，测试基本正确性；
// 数据3：103个随机整数；
// 数据4：104个随机整数；
// 数据5：105个随机整数；
// 数据6：105个顺序整数；
// 数据7：105个逆序整数；
// 数据8：105个基本有序的整数；
// 数据9：105个随机正整数，每个数字不超过1000。

// 输入样例:
// 11
// 4 981 10 -17 0 -20 29 50 8 43 -5
//
// 输出样例:
// -20 -17 -5 0 4 8 10 29 43 50 981

#include <iostream>
#include <vector>

void heapify(std::vector<int>& vec, const int start, const int end); 
void heapsort(std::vector<int>& vec);
void printvec(const std::vector<int>& vec);

int main(int argc, char* argv[]) {
  int N;
  std::cin >> N;
  std::vector<int> vec(N, 0);
  
  for (int i=0; i!=N; ++i) {
    std::cin >> vec[i];
  }

  heapsort(vec);
  printvec(vec);
  return 0;
}

// inline int parent(const int i) { return i / 2; }
// inline int lchild(const int i) { return i * 2; }
// inline int rchild(const int i) { return i * 2 + 1; }

template <typename T>
inline void swap(T& a, T& b) {
  T tmp = a;
  a = b;
  b = tmp;
}

void heapify(std::vector<int>& vec, const int start, const int end) {
  int dad = start;
  int son = dad * 2 + 1;
  while (son <= end ) {
    if (son + 1 <= end && vec[son] < vec[son + 1]) {
      ++son;
    }

    if (vec[dad] > vec[son]) {
      return;
    } else {
      swap(vec[dad], vec[son]);
      dad = son;
      son = dad * 2 + 1;
    }
  }
}

void heapsort(std::vector<int>& vec) {
  for (int i=vec.size()/2 - 1; i>=0; --i) {
    heapify(vec, i, vec.size() - 1);
  }

  for (int i=vec.size() - 1; i>0; --i) {
    swap(vec[0], vec[i]);
    heapify(vec, 0, i - 1);
  }
}

void printvec(const std::vector<int>& vec) {
  bool is_first = true;
  for (auto e : vec) {
    if (is_first) {
      is_first = false;
      std::cout << e;
    } else {
      std::cout << " " << e;
    }
  }
  std::cout << std::endl;
}
