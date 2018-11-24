#include <cstdio>
#include <unordered_map>

int main(int argc, char* argv[]) {
  int nRec, minDist;
  scanf("%d%d", &nRec, &minDist);

  std::unordered_map<char*, int> Data;
  char tmpstr[20];
  int tmpint;
  for (int i=0; i!=nRec; ++i) {
    scanf("%s %d\n", tmpstr, &tmpint);
    Data[tmpstr] += tmpint;
  }

  int nQuery;
  scanf("%d", &nQuery);
  for (int i=0; i!=nQuery; ++i) {
    scanf("%s", tmpstr);
    auto it = Data.find(tmpstr);
    if (Data.end() == it) {
      puts("No Info");
    } else {
      printf("%d\n", it->second);
    }
  }
  return 0;
}
