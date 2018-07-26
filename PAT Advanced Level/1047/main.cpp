#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
  ifstream cin("in2.txt");
#endif


  ios::sync_with_stdio(false);
  int student_num, course_num;
  cin >> student_num >> course_num;
  map<int, vector<string>> student_list;
  for (int i = 0; i != student_num; ++i) {
    string name;
    int num;
    cin >> name >> num;
    for (int j = 0; j != num; ++j) {
      int cn;
      cin >> cn;
      student_list[cn].push_back(name);
    }
  }

  for (auto it = student_list.begin(); it != student_list.end(); ++it) {
    cout << it->first << " " << it->second.size() << endl;
    sort(it->second.begin(), it->second.end());
    for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
      cout << *it2 << endl;
  }
  return 0;
}