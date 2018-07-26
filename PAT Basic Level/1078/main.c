#include <stdio.h>
// #include <stdlib.h>
#include <string.h>

#define MAX_LEN (1 << 10)
#define IS_NUM(a) (\
	(a) >= '0' && (a) <= '9'\
)

void decompress(const char str[]);
void compress(const char str[]);

int main(int argc, char* argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in3.txt", "r", stdin);
#endif

	char func;
	scanf("%c", &func);
	char str[MAX_LEN]/*, tmpch*/;
	getchar();
	// fgets(str, MAX_LEN, stdin);
	// scanf("%[^\n]%*c", str);
	fread(str, sizeof(char), MAX_LEN, stdin);
	// int i = 0;
	// while (-1 != (tmpch = getchar())) {
	// 	str[i++] = tmpch;
	// } str[i] = 0;

	// puts(str);
	if ('D' == func) {
		decompress(str);
	} else {
		compress(str);
	}
	return 0;
}

void decompress(const char str[]) {
	int i = 0, len = strlen(str);
	int num, numlen;
	char ch, numstr[10];
	while (i < len) {
		if (IS_NUM(str[i])) {
			sscanf(str + i, "%d", &num);
			sprintf(numstr, "%d", num);
			numlen = strlen(numstr);
			ch = str[i+numlen];
			for (int j=0; j!=num; ++j) {
				putchar(ch);
			}
			i += numlen + 1;
		} else {
			putchar(str[i++]);
		}
	}
}

void compress(const char str[]) {
	int num = 1, len = strlen(str);
	char last_ch = str[0];
	int i = 1;
	while (i < len + 1) {
		if (last_ch != str[i]) {
			if (1 != num) {
				printf("%d%c", num, last_ch);
				num = 1;
			} else {
				putchar(last_ch);
			}
			last_ch = str[i];
		} else {
			++num;
		}
		++i;
	}
}