#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1000

int main() {
	int n = 0, k = 0, tmp = 0;
	scanf("%d %d", &n, &k);
	int arr[MAX] = {0, };
	for (int i = 1; i <= n; i++) arr[i - 1] = i; // 1부터 n까지 저장

	if (n == 1 && k == 1) tmp = 1;
	if (n == 1 && n < k) tmp = n;
	else if (n == k) tmp = k;
	else tmp = k % n;
	
	printf("<");

	for (int i = 0; i < n; i++) {
		printf("%d", arr[tmp - 1]);
		if (i == n - 1) break; // 마지막 사람의 순서를 찍고 나온다.

		if (i != n - 1) printf(", ");
		arr[tmp - 1] = -1; // 제거된 사람은 -1로 배열에 표시한다.

		for (int i = 0; i < k; i++) {
			tmp++;
			if (tmp == n + 1) tmp %= n; // 원의 범위를 벗어나지 않게 한다.
			if (arr[tmp - 1] == -1) i--; // 제거된 사람은 세지 않는다.
		}
	}

	printf(">");
}
