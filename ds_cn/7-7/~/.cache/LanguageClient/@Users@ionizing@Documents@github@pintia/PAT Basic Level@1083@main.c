#include <stdio.h>
#define MAX 10001

int main(int argc, char* argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	int diff, repeat[MAX] = {0};
	int N, tmp;
	scanf("%d", &N);
	++N;
	for (int i=1; i!=N; ++i) {
		scanf("%d", &tmp);
		diff = tmp > i ? tmp - i : i - tmp;
		++repeat[diff];
	}

	for (int i=MAX-1; i!=-1; --i) {
		if (repeat[i] > 1) {
			printf("%d %d\n", i, repeat[i]);
		}
	}
	return 0;
}