// #include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <fstream>
// #include <string>

#define _HASH(x) int(\
	(x[0] - 'A') * 26 * 26 * 10 + \
	(x[1] - 'A') * 26 * 10 + \
	(x[2] - 'A') * 10 + \
	(x[3] - '0')\
)

int main(int argc, char* argv[]) {
	// std::ios::sync_with_stdio(false);
 //    std::cin.tie(0);

    setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);
    setvbuf(stdout, new char[1 << 20], _IOFBF, 1 << 20);

#ifndef ONLINE_JUDGE
 //    std::ifstream in("in.txt");
	// std::cin.rdbuf(in.rdbuf());
	freopen("in.txt", "r", stdin);
#endif

	std::vector<std::vector<int>> Data(26 * 26 * 26 * 10);
	int nStu, nCour;
	// std::cin >> nStu >> nCour;
	scanf("%d%d", &nStu, &nCour);

	int CourInd, tmpStu;
	char stuName[5];
	for(int i=0; i!=nCour; ++i) {
		// std::cin >> CourInd >> tmpStu;
		scanf("%d%d", &CourInd, &tmpStu);
		for (int j=0; j!=tmpStu; ++j) {
			// std::cin >> stuName;
			scanf("%s", stuName);
			if (0 == Data[_HASH(stuName)].size()) {
				Data[_HASH(stuName)].reserve(5);
			}
			Data[_HASH(stuName)].push_back(CourInd);
		}
	}

	for (int i=0; i!=nStu; ++i) {
		// std::cin >> stuName;
		// std::cout <<  stuName << ' ';
		// std::cout << Data[_HASH(stuName)].size();
		scanf("%s", stuName);
		printf("%s %zu", stuName, Data[_HASH(stuName)].size());
		std::sort(Data[_HASH(stuName)].begin(), Data[_HASH(stuName)].end());
		for (auto &i : Data[_HASH(stuName)]) {
			// std::cout << ' ' << i;
			printf(" %d", i);
		} 
		// std::cout << std::endl;
		puts("");
	}
	return 0;
}