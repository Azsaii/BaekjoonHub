#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int calc(int x, int y) {
	return pow(x, 2) + pow(y, 2);
}

int main() {
	int a, b, c;
	int max = 0;
	int other = 0;
	
	while (1) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0 && b == 0 && c == 0) return 0;

		max = ((a > b) && (a > c)) ? a : ((b > a) && (b > c)) ? b : c;

		if (max == a) { other = calc(b, c); } // a가 가장 큰 경우
		else if (max == b) { other = calc(a, c); } // b가 가장 큰 경우
		else{ other = calc(a, b); } // c가 가장 큰 경우

		if (pow(max, 2) == other) { printf("right\n"); }
		else printf("wrong\n");
	}
}