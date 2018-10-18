/* A `copy' of https://blog.csdn.net/tjj1998/article/details/80034671 */
#include <cstdio>
#include <stack>

#define Sqrt 316
#define MAX 100001

int block[317] = {0}, table[MAX] = {0};
std::stack<int> Stack;

void Push(const int e);
void Pop();
void PeekMedian(const int ind);

int main(int argc, char* argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int N, elem, ind;
	char command[20];
	scanf("%d", &N);
	for (int i=0; i!=N; ++i) {
		scanf("%s", command);
		switch (command[1]) {
			case 'u': scanf("%d", &elem); Push(elem); break;
			case 'o': Pop(); break;
			case 'e': ind = Stack.size() % 2 == 1 ? 
				(Stack.size() + 1) / 2 : Stack.size() / 2;
				PeekMedian(ind); break;
		}
	}
	return 0;
}

void Push(const int e) {
	Stack.push(e);
	++block[e/Sqrt];
	++table[e];
}

void Pop() {
	if (true == Stack.empty()) {
		puts("Invalid");
		return;
	} else {
		auto e = Stack.top();
		Stack.pop();
		--block[e/Sqrt];
		--table[e];
		printf("%d\n", e);
	}
}

void PeekMedian(const int ind) {
	if (true == Stack.empty()) {
		puts("Invalid");
		return;
	}

	int blocksum = 0, blockind = 0;
	while (blocksum + block[blockind] < ind) {
		blocksum += block[blockind];
		++blockind;
	}
	int target = blockind * Sqrt;
	while (blocksum + table[target] < ind) {
		blocksum += table[target];
		++target;
	}
	printf("%d\n", target);
}