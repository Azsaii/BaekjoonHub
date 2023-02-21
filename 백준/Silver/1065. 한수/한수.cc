#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int result(int x) {
	int res = 0, a, b, c, d;
	for (int i = 1; i <= x; i++) {
		if (i / 100 == 0) {
			res += 1;
		}
		else {
			a = i - (i / 10 * 10);
			b = (i - i / 100 * 100)/10;
			c = (i - i / 1000 * 1000) / 100;
			d = i / 1000;
			if (d == 0) {
				if (a - b == b - c) {
					res += 1;
				}
			}
		}
	}
	return res;
}
int main() {
	int a;
	scanf("%d", &a);
	a = result(a);
	printf("%d", a);
	return 0;
}