#include <cstdio>
#include <fstream>
#include <map>
#include <algorithm>
#include <string>
#include <set>

std::map<std::string, std::set<int>> Data;

int main(int argc, char* argv[]) {	
#ifndef ONLINE_JUDGE
	 freopen("in.txt", "r", stdin);
#endif

	int nStu, nCour;
	// std::cin >> nStu >> nCour;
	scanf("%d%d", &nStu, &nCour);

	int CourInd, tmpStu;
	std::string stuName;
	char tmpName[5];
	for (int i=0; i!=nCour; ++i) {
		// std::cin >> CourInd >> tmpStu;
		scanf("%d%d", &CourInd, &tmpStu);
		for (int j=0; j!=tmpStu; ++j) {
			// std::cin >> stuName;
			scanf("%s", tmpName);
			stuName = std::string(tmpName);
			Data[stuName].insert(CourInd);
		}
	}

	for (int i=0; i!=nStu; ++i) {
		// std::cin >> stuName;
		// std::cout << stuName << ' ';
		// std::cout << Data[stuName].size();
		scanf("%s", tmpName);
		stuName = std::string(tmpName);
		printf("%s ", tmpName);
		printf("%zu", Data[stuName].size());
		for ( auto i : Data[stuName] ) {
			// std::cout << ' ' << i;
			printf(" %d", i);
		} 
		// std::cout << std::endl;
		puts("");
	}
	return 0;
}