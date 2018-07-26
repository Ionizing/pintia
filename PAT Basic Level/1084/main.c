#include <stdio.h>
#include <string.h>

#define MAX_LEN 100000
char res[MAX_LEN] = {0}, tmp[MAX_LEN] = {0};

void Process(char str[], char tmp[]);

int main(int argc, char* argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	int N;
	scanf("%s %d", res, &N);
	for (int i=0; i!=N-1; ++i) {
		Process(res, tmp);
	}
	puts(res);
}

void Process(char str[], char tmp[]) {
	tmp[0] = 0;
	int num = 1, len = strlen(str);
	char last_ch = str[0];
	int i = 1;
	while (i < len + 1) {
		if (last_ch != str[i]) {
			sprintf(tmp + strlen(tmp), "%c%d", last_ch, num);
			last_ch = str[i];
			num = 1;
		} else {
			++num;
		}
		++i;
	}
	strcpy(str, tmp);
}