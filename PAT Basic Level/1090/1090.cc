#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <vector>

using SetInt = std::set<int>;

std::map<int, SetInt> Conflict;


int main(int argc, char* argv[]) {
  int N, M;
  std::cin >> N >> M;
  
  for (int i=0; i!=N; ++i) {
    int _A, _B;
    std::cin >> _A >> _B;
    Conflict[_A].insert(_B);
    Conflict[_B].insert(_A);
  }

  for (int i=0; i!=M; ++i) {
    std::vector<int> goodlist;
    int length;
    std::cin >> length;
    for (int j=0; j!=length; ++j) {
      int good;
      std::cin >> good;
      goodlist.emplace_back(good);
    }
    std::sort(goodlist.begin(), goodlist.end());

    bool isFound = false;
    for (const int e : goodlist) {
      std::vector<int> v_intersection;
      std::set_intersection(goodlist.begin(), goodlist.end(),
                            Conflict[e].begin(), Conflict[e].end(),
                            std::back_inserter(v_intersection));      
      if (!isFound and 0 != v_intersection.size()) {
        isFound = true;
        std::cout << "No" << std::endl;
      }
    }
    if (!isFound) {
      std::cout << "Yes" << std::endl;
    }
  }
  
  return 0;
}
