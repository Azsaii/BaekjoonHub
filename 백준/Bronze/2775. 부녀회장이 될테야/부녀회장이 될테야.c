#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int size = 0;
	scanf("%d", &size);

	int k = 0, n = 0;
	int res[14] = {0, };

	while (size--) {
		scanf("%d", &k);
		scanf("%d", &n);
		for (int i = 0; i < 14; i++) res[i] = i + 1;

		for (int i = 1; i <= k; i++) {
			for (int j = 1; j < n; j++) {
				res[j] += res[j - 1]; // 아랫집 j - 1호의 사람수를 더해서 갱신.
			}
		}
		printf("%d\n", res[n - 1]);
	}
	
}