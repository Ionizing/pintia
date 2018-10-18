// 已知有两个等长的非降序序列S1, S2, 设计函数求S1与S2并集的中位数。有序序列A
// 0 ,A 1 ,⋯,A N−1 的中位数指A (N−1)/2 的值,即第⌊(N+1)/2⌋个数（A 0 为第1个数）。

// in: 5
// 1 3 5 7 9
// 2 3 4 5 6
// out:
// 4

// In2:
// 6
// -100 -10 1 1 1 1
// -50 0 2 3 4 5
// Out:
// 1

#include <iostream>
#include <queue>

int main(int argc, char* argv[]) {
  int N;
  std::queue<int> q1, q2;
  std::cin >> N;
  int tmp;
  for (int i=0; i!=N; ++i) {
    std::cin >> tmp;
    q1.push(tmp);
  }

  for (int i=0; i!=N; ++i) {
    std::cin >> tmp;
    q2.push(tmp);
  }

  for (int i=0; i!=N; ++i) {
    if (q1.front() < q2.front()) {
      tmp = q1.front();
      q1.pop();
    } else {
      tmp = q2.front();
      q2.pop();
    }
  }

  std::cout << tmp << std::endl;
}
