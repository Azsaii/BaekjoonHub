#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 501
#define INF 9999999999

int main() {
	int m = 0, n = 0, b = 0;
	int res = 0;
	int map[MAX][MAX] = {0, };

	scanf("%d %d %d", &n, &m, &b);

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			scanf("%d", &map[i][k]);
		}
	}
	int plus = 0; // 제거할 블록의 수
	int minus = 0; // 추가할 블록의 수
	int min = INF;

	for (int i = 0; i < 257; i++) {
		plus = 0;
		minus = 0;
		
		for (int t = 0; t < n; t++) {
			for (int k = 0; k < m; k++) {
				if (i < map[t][k]) plus += map[t][k] - i;
				else if (i > map[t][k]) minus += i - map[t][k];
			}
		}

		// 블록이 부족하면 맞지 않는 높이.
		if (b + plus - minus < 0) continue;
		if (min >= plus * 2 + minus) { // 최소 시간을 갱신. 최소 시간이 같은 경우, 더 높은 층수가 출력 되야함
			res = i;
			min = plus * 2 + minus;
		}
	}

	printf("%d %d", min, res);
	return 0;
}