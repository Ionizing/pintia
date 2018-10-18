/* 7-1 最大子列和问题（20 分） */

#include <stdio.h>

int arr[100000];

int MaxSumSeq(const int N, const int arr[]);

int main() {

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	int N;
	scanf("%d", &N);

	for (int i=0; i!=N; ++i) {
		scanf("%d", &arr[i]);
	}

	int maxsum = MaxSumSeq(N, arr);
	printf("%d\n", maxsum);
	return 0;
}

int MaxSumSeq(const int N, const int arr[]) {
	int last_sum = 0, curr_sum = 0;
	for (int i=0; i!=N; ++i) {
		curr_sum += arr[i];
		if (curr_sum > last_sum) {
			last_sum = curr_sum;
		}
		if (curr_sum < 0) {
			curr_sum = 0;
		}
	}

	return last_sum;
}
