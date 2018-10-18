#include <cstdio>
#include <vector>
#include <algorithm>

#define _HASH(x) (\
	(x[0] - 'A') * 26 * 26 * 10 +\
	(x[1] - 'A') * 26 * 10 +\
	(x[2] - 'A') * 10 +\
	(x[3] - '0') \
)

#define _UNHASH(val, str) do {\
	str[4] = 0; \
	str[3] = val % 10 + '0'; \
	str[2] = val % (10 * 26) / 10 + 'A'; \
	str[1] = val % (10 * 26 * 26) / (10 * 26) + 'A'; \
	str[0] = val / (10 * 26 * 26) + 'A'; \
} while (0)

int main(int argc, char* argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	int stuNum, couNum;
	scanf("%d%d", &stuNum, &couNum);
	getchar();
	std::vector<std::vector<int>> Course(couNum + 1, std::vector<int>());
	char name[5];
	int num, couInd, hashedName;
	for (int i=0; i!=stuNum; ++i) {
		scanf("%s %d", name, &num);
		hashedName = _HASH(name);
		for (int j=0; j!=num; ++j) {
			scanf("%d", &couInd);
			if (Course[couInd].size() == 0) {
				Course[couInd].reserve(5);
			}
			Course[couInd].push_back(hashedName);
		} getchar();
	}

	for (int i=1; i!=couNum + 1; ++i) {
		printf("%d %zu\n", i, Course[i].size());
		std::sort(Course[i].begin(), Course[i].end());
		for (auto j : Course[i]) {
			_UNHASH(j, name);
			puts(name);
		}
	}
	return 0;
}