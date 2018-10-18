#include <cstdio>
#include <set>
#include <stack>

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	int N;
	char command[20];
	scanf("%d", &N);
	std::stack<int> Stack;
	std::multiset<int> Set;

	int elem;
	for (int i=0; i!=N; ++i) {
		scanf("%s", command);
		if ('o' == command[1]) {
			if (true == Stack.empty()) {
				puts("Invalid");
			} else {
				elem = Stack.top();
				printf("%d\n", elem);
				Stack.pop();
				Set.erase(elem);
			}
		} else if ('e' == command[1]) {
			auto len = Stack.size();
			if (0 == len) {
				puts("Invalid");
				continue;
			}
			int median = (len % 2 == 0) ? len / 2 -1 : (len + 1) / 2 -1;
			auto it = Set.begin();
			for (int i=0; i!=median; ++i) {
				++it;
			}
			printf("%d\n", *it);
		} else {
			scanf("%d", &elem);
			Set.insert(elem);
			Stack.push(elem);
		}
	}
	return 0;
}