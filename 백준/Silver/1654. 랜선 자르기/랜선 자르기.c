#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10000

int main() {
	int k = 0, n = 0;
	unsigned long long int max = 0, min = 0, res = 0;
	unsigned long long int length[MAX] = {0, };
	scanf("%d %d", &k, &n);

	for (int i = 0; i < k; i++) {
		scanf("%d", &length[i]);
		if (i == 0) max = length[i];
		else {
			if (max < length[i]) max = length[i];
		}
	}
	if (k == 1 && max < n) {
		printf("0");
		return 0;
	}
	res = max; // 최대 길이
	int tmp = 0; // k개를 res(cm)로 자른 개수
	int check = 0;

	while (1) {
		for (int i = 0; i < k; i++) {
			tmp += length[i] / res;
		}
		if (tmp >= n) min = res + 1;
		else if (tmp < n) max = res - 1;

		if (((max + min) / 2) == res) check++;
		if (check == 2) break;

		res = (max + min) / 2;
		tmp = 0;
	}

	printf("%d", res);
	return 0;
}