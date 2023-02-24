#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int num = 0;
	scanf("%d", &num);

	int count = 665;
	int tmp = 0;

	while (num) {
		count++;
		tmp = count;
		while (tmp != 0) { // 0이 될때까지 자릿수를 제거하면서 검사한다.
			if (tmp % 1000 == 666) {
				num--;
				break;
			}
			else tmp /= 10;
		}
	}
	printf("%d", count);
}