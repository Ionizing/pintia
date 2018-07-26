/* timeout */

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

#pragma pack(push)
#pragma pack(1)
struct Record {
	char Name[9] = "";
	int Age = 0;
	int Wealth = 0;
};
#pragma pack(pop)

std::vector<std::vector<Record>> Data(201);

int main(int argc, char* argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	int nPeople, nQuery;
	scanf("%d %d", &nPeople, &nQuery);
	for (int i=0; i!=nPeople; ++i) {
		Record tmp;
		scanf("%s %d %d", tmp.Name, &(tmp.Age), &(tmp.Wealth));
		Data[tmp.Age].push_back(tmp);
	}

	int maxDisp, minAge, maxAge;
	int cnt;
	std::vector<Record> tmp;
	for (int i=0; i!=nQuery; ++i) {
		scanf("%d%d%d", &maxDisp, &minAge, &maxAge);
		printf("Case #%d:\n", i + 1);
		tmp.resize(0);
		tmp.reserve(5);
		for (int j=minAge; j<=maxAge; ++j) {
			for (const auto k : Data[j]) {
				tmp.push_back(k);
			}
		}

		if (0 == tmp.size()) {
			puts("None");
		} else {
			cnt = 0;
			std::sort(tmp.begin(), tmp.end(), [](
				const Record a, const Record b){
				if (a.Wealth != b.Wealth) {
					return a.Wealth > b.Wealth;
				} else if (a.Age != b.Age) {
					return a.Age < b.Age;
				} else {
					return strcmp(a.Name, b.Name) < 0;
				}
			});

			for (const auto j : tmp) {
				if (++cnt > maxDisp) {
					break;
				}

				printf("%s %d %d\n", j.Name, j.Age, j.Wealth);
			}
		}
	}
	return 0;
}