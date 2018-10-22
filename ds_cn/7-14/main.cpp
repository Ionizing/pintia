// 给定大量手机用户通话记录，找出其中通话次数最多的聊天狂人。

// 输入格式:

// 输入首先给出正整数N（≤10
// ​5
// ​​ ），为通话记录条数。随后N行，每行给出一条通话记录。简单起见，这里只列出拨出方和接收方的11位数字构成的手机号码，其中以空格分隔。

// 输出格式:

// 在一行中给出聊天狂人的手机号码及其通话次数，其间以空格分隔。如果这样的人不唯一，则输出狂人中最小的号码及其通话次数，并且附加给出并列狂人的人数。

// 输入样例:

// 4
// 13005711862 13588625832
// 13505711862 13088625832
// 13588625832 18087925832
// 15005713862 13588625832
// 输出样例:

// 13588625832 3

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main(int argc, char* argv[]) {
  int N;
  std::cin >> N;
  std::unordered_map<long long, int> data;

  long long name;
  for (int i=0; i!=2*N; ++i) {
    std::cin >> name;
    ++data[name];
  }

  using pt = std::pair<long long, int>;
  std::vector<pt> vec;
  for (const auto e : data) {
    vec.push_back(e);
  }
  
  std::sort(vec.begin(), vec.end(), [](pt a, pt b){
      if (a.second != b.second) {
        return a.second > b.second;
      } else {
        return a.first < b.first;
      } }); // end of std::sort
  
  int _max = vec[0].second;
  std::cout << vec[0].first << " " << vec[0].second;
  int cnt = 0;
  for (int i=0; i!=vec.size(); ++i) {
    if (vec[i].second == _max) {
      ++cnt;
    } else {
      break;
    }
  }

  if (1 != cnt) {
    std::cout << " " << cnt;
  }

  std::cout << std::endl;
  return 0;
}
