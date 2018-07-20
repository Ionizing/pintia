#include <cstdio>
#include <vector>
#include <queue>

#define INT_MAX 2147483647
#define _MIN(a) ( \
	(long int)INT_MAX < (a) ? INT_MAX : (a) \
)
#define _MIN2(a, b) ( \
	(a) < (b) ? (a) : (b) \
)

int main(int argc, char* argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	// setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);
 //    setvbuf(stdout, new char[1 << 20], _IOFBF, 1 << 20);

	int m;
	scanf("%d", &m);
	std::queue<int> Q1;
	long int tmp;
	for (int i=0; i!=m; ++i) {
		scanf("%ld", &tmp);
		Q1.push(_MIN(tmp));
	}
	Q1.push(INT_MAX);

	int n;
	scanf("%d", &n);
	std::queue<int> Q2;
	int cnt = 0;
	for (int i=0; i!=n; ++i) {
		scanf("%ld", &tmp);
		Q2.push(_MIN(tmp));
		if (cnt == (n + m - 1) / 2) {
			printf("%d\n", _MIN2(Q1.front(), Q2.front()));
			return 0;
		}

		if (Q1.front() < Q2.front()) {
			Q1.pop();
		} else {
			Q2.pop();
		}

		++cnt;
	}


	Q2.push(INT_MAX);
	while (cnt < (n + m - 1) / 2) {
		if (Q1.front() < Q2.front()) {
			Q1.pop();
		} else {
			Q2.pop();
		}
		++cnt;
	}

	printf("%d", _MIN2(Q1.front(), Q2.front()));
	return 0;
}