#include <stdio.h>
#include <stdlib.h>

int union_size(const int* a, const int* b);
int set_size(const int* a);
int cmp(const void* a, const void* b);

int Sets[50][10001] = {0}; /* Sets[i][0] 为哨兵，存储当前的数组的大小 */


int main(int argc, char* argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in2.txt", "r", stdin);
#endif

	int nSets;
	scanf("%d", &nSets);

	int size;
	for (int i=0; i!=nSets; ++i) {
		scanf("%d", &size);
		Sets[i][0] = size;
		for (int j=1; j<=size; ++j) {
			scanf("%d", &Sets[i][j]);
		} 
	}

	int nQuery;
	int ia, ib;
	scanf("%d", &nQuery);
	for (int i=0; i!=nQuery; ++i) {
		scanf("%d%d", &ia, &ib);
		--ia, --ib;
		qsort(&Sets[ia][1], Sets[ia][0], sizeof(int), cmp);
		qsort(&Sets[ib][1], Sets[ib][0], sizeof(int), cmp);
		// printf("  @35\n");
		// for(int j=1; j<=Sets[ib][0]; ++j) {
		// 	printf(" %d", Sets[ib][j]);
		// } puts("");
		// printf("set_size  = %d  %d\n", set_size(Sets[ia]), set_size(Sets[ib]));
		int nCommon = union_size(Sets[ia], Sets[ib]),	
			nTotal = set_size(Sets[ia]) + set_size(Sets[ib]) - nCommon;
		double result = (nCommon + .0) / nTotal * 100;
		printf("%.1f%%\n", result);
	}
	return 0;
}

int cmp(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

/* 保证传入的 a 和 b 都是有序即可，允许其中有重复 
其中 a 指针起始位置指向哨兵；
*/
int union_size(const int* a, const int* b) {
	// printf(" @57 set_size =  %d %d\n", *a, *b);
	const int* const a_end = a + 1 + *a;
	const int* const b_end = b + 1 + *b;
	++a, ++b;
	int cnt = 0;

	int last_a = -1, last_b = -1;
	while (a < a_end && b < b_end) {
		// printf("*a = %d, last_a = %d, *b = %d, last_b = %d\n", 
		// 	*a, last_a, *b, last_b);

		if (*a < *b) {
			last_a = *a;
			++a;
			while (*a == last_a && a < a_end) {
				++a;
			}
		} else if (*a > *b) {
			last_b = *b;
			++b;
			while (*b == last_b && b < b_end) {
				++b;
			}
		} else {
			last_a = *a, last_b = *b;
			++cnt;
			++a, ++b;

			while (*a == last_a && a < a_end) {
				++a;
			}
			while (*b == last_b && b < b_end) {
				++b;
			}
		}
	}

	return cnt;
}

int set_size(const int* a) {
	int size = a[0];
	const int* end = a + size;
	int last_value = -1;

	++a;
	while (a != end) {
		if (*a == last_value) {
			--size;
		} else {
			last_value = *a;
		}
		++a;
	}

	// printf(" @92 set_size = %d\n", size);
	return size;
}