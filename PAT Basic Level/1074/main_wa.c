#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 21

int* convert(const char str[], const int is_carry_list) {
	int len = strlen(str);
	int* res = (int*)malloc(sizeof(int) * MAX_LEN);
	for (int i=0; i!=MAX_LEN; ++i) {
		res[i] = 0;
	}
	for (int i=0; i!=len; ++i) {
		res[len-i-1] = (str[i] - '0' == 0 && 1 == is_carry_list) ? 10 : str[i] - '0';
	}
	return res;
}
void printarray(const int arr[], const int size) {
	for (int i=0; i!=size; ++i) {
		printf(" %d", arr[i]);
	} puts("");
}

// void initstr(char str[]) {
// 	for (int i=0; i!=MAX_LEN; ++i) {
// 		str[i] = '\0';
// 	}
// }

int main(int argc, char* argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	char carry_str[MAX_LEN] = {0},
		a_str[MAX_LEN] = {0},
		b_str[MAX_LEN] = {0};
	scanf("%s\n%s\n%s", carry_str, a_str, b_str);
	int* carry_list = convert(carry_str, 1);
	int* a = convert(a_str, 0);
	int* b = convert(b_str, 0);
	// printarray(carry_list, strlen(carry_str));
	int res[MAX_LEN] = {0};
	int carry = 0, i;
	for (i=0; i!=strlen(carry_str); ++i) {
		res[i] = (a[i] + b[i] + carry) % carry_list[i];
		carry = (a[i] + b[i] + carry) / carry_list[i];

		// printf(" @42 res[%d] = %d, carry = %d\n", i, res[i], carry);
	}

	int is_head = 1;
	for (int i=MAX_LEN; i!=-1; --i) {
		if (0 != res[i] && 1 == is_head) {
			is_head = 0;
		}

		if (0 == is_head) {
			printf("%d", res[i]);
		}
	} puts("");
	return 0;
}