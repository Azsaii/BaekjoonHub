#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int GCD(int x, int y) { // 최대공약수 구하는 함수
	int min = (x < y) ? x : y;
	for (int i = min; i >= 1; i--) {
		if (x % i == 0 && y % i == 0) return i;
	}
}
int LCM(int x, int y) { // 최소공배수 구하는 함수
	if (x == y) return x;
	int min = (x < y) ? x : y;
	int max = (x > y) ? x : y;
	int minTmp = min;
	int maxTmp = max;
	int i = 1;
	while (1) {
		maxTmp = max;
		maxTmp *= i;
		for (int k = 1; minTmp <= maxTmp; k++) {
			minTmp = min;
			minTmp *= k;
			if (minTmp == maxTmp) return minTmp;
		}
		i++;
	}
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);

	printf("%d\n%d", GCD(a, b), LCM(a, b));
}