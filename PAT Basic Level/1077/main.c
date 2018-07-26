#include <stdio.h>
#include <stdlib.h>

int sScore[100] = {0};
int cmp(const void* a, const void* b) {
	return *(int*) a < *(int*) b;
}

int main(int argc, char* argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	int nGroup, fullScore;
	scanf("%d%d", &nGroup, &fullScore);
	int tScore = 0, nValid, sumValid, result;
	for (int i=0; i!=nGroup; ++i) {
		nValid = 0;
		sumValid = 0;
		result = 0;
		scanf("%d", &tScore);
		for (int j=0; j!=nGroup-1; ++j) {
			int tmpScore;
			scanf("%d", &tmpScore);
			if (tmpScore >= 0 && tmpScore <= fullScore) {
				sScore[nValid++] = tmpScore;
				sumValid += tmpScore;
			}
		}
		qsort(sScore, nValid, sizeof(int), cmp);
		sumValid -= sScore[0] + sScore[nValid - 1];
		result = (int)(((sumValid + 0.0)/(nValid - 2) + tScore)/2 + 0.5);
		printf("%d\n", result);
	}
	return 0;
}