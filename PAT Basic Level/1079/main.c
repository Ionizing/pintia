#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 2000

typedef enum {false, true} bool;

bool isPalindromic(const char* str);
void reverse(char* str1, char* str2);
void add(const char* a, const char* b, char* c);

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	char A[MAX_LEN] = {0}, B[MAX_LEN] = {0}, 
		tmp[MAX_LEN] = {0}, tmprev[MAX_LEN] = {0};
	scanf("%s", A);
	// reverse(A, B);
	// add(A, B, tmprev);
	// reverse(tmprev, tmp);
	// puts(A);
	// puts(B);
	// puts(tmp);
	int cnt = 0;
	while (false == isPalindromic(A)) {
		if (10 == cnt) {
			puts("Not found in 10 iterations.");
			return 0;
		}
		reverse(A, B);
		add(A, B, tmprev);
		reverse(tmprev, tmp);
		printf("%s + %s = %s\n", A, B, tmp);
		strcpy(A, tmp);
		strcpy(B, tmprev);
		++cnt;
	}
	printf("%s is a palindromic number.\n", A);
	return 0;
}

bool isPalindromic(const char* str) {
	int len = strlen(str);
	int beg = 0, end = len - 1;
	while (beg < end) {
		if (str[beg] != str[end]) {
			return false;
		}
		++beg, --end;
	}
	return true;
}

void reverse(char* str1, char* str2) {
	int len = strlen(str1);
	char* p1 = str1;
	char* p2 = str2 + len - 1;
	while (p2 != str2 - 1) {
		*p2 = *p1;
		++p1, --p2;
	}
	str2[len] = 0;
}

void add(const char* a, const char* b, char* c) {
	int len = strlen(a);
	int carry = 0, i = 0;
	for (i=0; i!=len; ++i) {
		c[i] = (a[i] - '0' + b[i] - '0' + carry) % 10 + '0';
		carry = (a[i] - '0' + b[i] - '0' + carry) / 10;
	}
	while (0 != carry) {
		c[i] = carry % 10 + '0';
		carry /= 10;
		++i;
	}
	c[i] = 0;
	/* 此时字符串是反着的，需要反转一次 */
}