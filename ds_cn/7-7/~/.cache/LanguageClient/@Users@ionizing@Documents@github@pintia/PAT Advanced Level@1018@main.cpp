//我的思路是暴力的，首先是用单源有权最短路算法把最短路算出来。在计算时，普通的寻路算法因为不需要考虑等长
//路径的情况，因此path[]的值是之前一个节点，而因为这道题要考虑路径相等的可能性，因此path[]的值是上一个
//可能节点的集合。
//得到这样一条path之后，我就用把所有可能的路径都暴力求出来，保存在一个shortest_path变量下。
//这个变量的每一个值都是一条从0开始到达目的地的路径。
//之后我对这样的路径集合进行遍历，找到需要带出和带回的最小自行车数量
//之后再对这样的路径集合进行一次遍历，找到带出最小自行车数的路径的序号。
//如果这个序号唯一，那么直接输出结果就行，如果序号不唯一，那么再在其中寻找最小带回自行车数量。
//最后就是输出了。

#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;
#define INT_MAX numeric_limits<int>::max()

struct node {
  int index;
  int weight;
  node(const int &a, const int &b) : index(a), weight(b){};
  bool operator<(const node &a) const { return weight < a.weight; };
  bool operator>(const node &a) const { return weight > a.weight; };
};

using min_heap = priority_queue<node, vector<node>, greater<node>>;

void path_caculate(vector<vector<int>> &path, int sta, vector<int> single_path);
vector<vector<int>> shortest_path; //一个全局变量，用来保存最短路径

int main() {

  ios::sync_with_stdio(false);
  int cap, sta_count, ill_sta, road_num;
  cin >> cap >> sta_count >> ill_sta >> road_num;
  vector<int> stations(sta_count + 1, INT_MAX); // 0号节点是PBMC
  for (int i = 1; i != sta_count + 1; ++i) {
    cin >> stations[i];
  }

  vector<vector<int>> maps(sta_count + 1, vector<int>(sta_count + 1, 0));
  for (int i = 0; i != road_num; ++i) {
    int t1, t2, t3;
    cin >> t1 >> t2 >> t3;
    maps[t1][t2] = maps[t2][t1] = t3;
  }
  //以上数据就录入完了。现在开始做寻路
  vector<vector<int>> path(sta_count + 1); //加一万万不能忘
  vector<int> min(sta_count + 1, INT_MAX); //指示了每个节点当前最短路径
  min_heap vertex;
  vertex.push(node(0, 0));
  min[0] = 0;

  while (!vertex.empty()) {
    int tmp = vertex.top().index;
    vertex.pop();
    for (int i = 0; i != sta_count + 1; ++i) {
      if (maps[tmp][i] != 0) {
        if (min[i] > min[tmp] + maps[tmp][i]) {
          min[i] = min[tmp] + maps[tmp][i];
          vertex.push(node(i, min[i]));
          path[i] = vector<int>(1, tmp);
        } else if (min[i] == min[tmp] + maps[tmp][i]) {
          path[i].push_back(tmp);
        }
      }
    }
  }
  //此时最短路径就求完了，我们可以知道到ill_sta到底哪条路最近了。
  //然后我们把这些路径都求出来。

  path_caculate(path, ill_sta, vector<int>());
  //此时shortest_path已经被填满
  vector<int> take_out(shortest_path.size());
  vector<int> take_back(shortest_path.size());
  int min_take_out = INT_MAX;
  int min_take_back = INT_MAX;

  for (int i = 0; i != shortest_path.size(); ++i) {
    int now_left = 0;
    int take = 0;
    for (int j = 0; j != shortest_path[i].size(); ++j) {
      if (stations[shortest_path[i][j]] + now_left < cap / 2) {
        //就是现在站点的车加上你带过来的，还不足一半，那就调高带出来的车的数量
        take += cap / 2 - stations[shortest_path[i][j]] - now_left;
        now_left = 0;
      } else {
        //现在站点的车加上带过来的，刚好一半甚至超了一半，take显然不用变，但now_left就要增加了
        now_left += stations[shortest_path[i][j]] - cap / 2;
      }
    }
    if (take < min_take_out)
      min_take_out = take;
    if (now_left < min_take_back)
      min_take_back = now_left;
    take_out[i] = take;
    take_back[i] = now_left;
  }
  vector<int> equal_take_out; //最少带出
  for (int i = 0; i != shortest_path.size(); ++i) {
    if (take_out[i] == min_take_out) {
      equal_take_out.push_back(i);
    }
  }

  if (equal_take_out.size() == 1) {
    int index = equal_take_out[0];
    cout << take_out[index] << " " << 0;
    for (auto x : shortest_path[index]) {
      cout << "->" << x;
    }
    cout << " " << take_back[index] << endl;
  } else {
    for (auto index : equal_take_out) {
      if (take_back[index] == min_take_back) {
        cout << min_take_out << " " << 0;
        for (auto x : shortest_path[index]) {
          cout << "->" << x;
        }
        cout << " " << min_take_back << endl;
      }
    }
  }

  return 0;
}

void path_caculate(vector<vector<int>> &path, int sta,
                   vector<int> single_path) {

  //该算法中，0节点不会进入队列
  if (sta == 0) {
    shortest_path.push_back(
        vector<int>(single_path.rbegin(), single_path.rend()));
    //因为singel_path是反的，这里把他弄正了
    return;
  } else {
    single_path.push_back(sta);
    for (auto x : path[sta]) {
      path_caculate(path, x, single_path);
    }
  }
}