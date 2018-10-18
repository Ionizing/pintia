#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

std::vector<int> Union(const std::set<int>& a, const std::set<int>& b);

int main(int argc, char* argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	int nSet;
	scanf("%d", &nSet);
	std::vector<std::set<int>> Sets(nSet);

	int size, tmpelem;
	for (int i=0; i!=nSet; ++i) {
		scanf("%d", &size);
		for (int j=0; j!=size; ++j) {
			scanf("%d", &tmpelem);
			Sets[i].insert(tmpelem);
		}
	}

	int nQuery;
	scanf("%d", &nQuery);
	int ia, ib;
	// std::set<int> U;
	std::vector<int> Uvec;
	for (int i=0; i!=nQuery; ++i) {
		// U.clear();
		scanf("%d%d", &ia, &ib);
		--ia, --ib;

		// U = Sets[ia];
		// U.insert(Sets[ib].begin(), Sets[ib].end());  // Use this will lead to timeout
	
		Uvec = Union(Sets[ia], Sets[ib]);
		int nTotal = Uvec.size(),
			nCommon = Sets[ia].size() + Sets[ib].size() - nTotal;
		double result = (nCommon + .0) / nTotal;
		printf("%.1f%%\n", result * 100);
	}
	return 0;
}

std::vector<int> Union(const std::set<int>& a, const std::set<int>& b) {
	std::vector<int> result;
	result.reserve(5);
	auto ia = a.begin(), ib = b.begin();
	while (ia != a.end() and ib != b.end()) {
		if (*ia < *ib) {
			result.push_back(*ia++);
		} else if (*ia > *ib) {
			result.push_back(*ib++);
		} else {
			result.push_back(*ia);
			++ia, ++ib;
		}
	}

	while (ia != a.end()) {
		result.push_back(*ia++);
	}

	while (ib != b.end()) {
		result.push_back(*ib++);
	}

	return result;
}
