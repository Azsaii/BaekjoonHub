#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);

	int minWidth =  (x <= w - x) ? x : (w - x); // 경계선과의 최소 거리(x축)를 구한다.
	int minHeight = (y <= h - y) ? y : (h - y); // 경계선과의 최소 거리(y축)를 구한다.
	int res = (minWidth <= minHeight) ? minWidth : minHeight; // 둘 중 더 가까운 거리를 구한다.

	printf("%d", res);
}