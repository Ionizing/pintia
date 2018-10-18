// timeout

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char tmpstr[11];

int main(int argc, char* argv[]) {
	int N;
	scanf("%d", &N);
	long int cnt = 0;
	for (int i=0; i!=N+1; ++i) {
		sprintf(tmpstr, "%d", i);
		for (int j=0; j!=strlen(tmpstr); ++j) {
			if ('1' == tmpstr[j]) {
				++cnt;
			}
		}
	}

	printf("%ld\n", cnt);
	return 0;
}