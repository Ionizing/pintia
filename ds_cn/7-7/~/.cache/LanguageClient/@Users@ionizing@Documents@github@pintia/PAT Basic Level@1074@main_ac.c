#include <stdio.h>
#include <string.h>

#define MAX_LEN 21
#define MAX(a, b) (\
	(a) > (b) ? (a) : (b)\
)

void fillzero(char* str, const int lenA, const int len);

int main(int argc, char* argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	char carry_list[MAX_LEN], a[MAX_LEN], b[MAX_LEN], res[MAX_LEN] = {0};
	scanf("%s\n%s\n%s", carry_list, a, b);
	int lenA = strlen(a), lenB = strlen(b), lenC = strlen(carry_list);
	int len = MAX_LEN;
	fillzero(a, lenA, len);
	fillzero(b, lenB, len);
	fillzero(carry_list, lenC, len);

	// puts(carry_list);
	// puts(a);
	// puts(b);
	int carry = 0;
	for (int i=len-1; i!=-1; --i) {
		res[i] = (a[i] + b[i] - 2*'0' + carry) % 
			('0' == carry_list[i] ? 10 : carry_list[i] - '0') + '0';
		carry = (a[i] + b[i] - 2*'0' + carry) / 
			('0' == carry_list[i] ? 10 : carry_list[i] - '0');
	}

	for (int i=0; i!=len; ++i) {
		if ('0' != res[i]) {
			puts(res + i);
			break;
		}

		if (i == len - 1) {
			puts("0");
		}
	}
	return 0;
}

void fillzero(char* str, const int lenA, const int len) {
	int i = len, step = len - lenA;
	while (-1 != i) {
		if (i >= step) {
			str[i] = str[i - step];
		} else {
			str[i] = '0';
		}
		--i;
	}
}