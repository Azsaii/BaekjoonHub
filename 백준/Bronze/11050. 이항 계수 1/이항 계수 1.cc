#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fac(int x) {
	int res = 1;
	for (int i = 2; i <= x; i++)
		res *= i;
	return res;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	printf("%d", fac(n) / (fac(k) * fac(n - k)));
}