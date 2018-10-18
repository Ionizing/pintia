#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	int K;
	scanf("%d", &K);

	int* arr = (int*)malloc(K * sizeof(int));
	for (int i=0; i!=K; ++i) {
		arr[i] = -1;
	}

	int tmpData;
	scanf("%d", &tmpData);
	int cnt = -1;
	while (tmpData >= 0) {
		arr[(++cnt) % K] = tmpData;
		scanf("%d", &tmpData);
	}

	if (-1 == arr[(cnt + 1) % K]) {
		puts("NULL");
	} else {
		printf("%d\n", arr[(cnt + 1) % K]);
	}
	return 0;
}