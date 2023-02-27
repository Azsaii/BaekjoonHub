#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int num = -1;
	int tmpA = 0;
	int tmpB = 0;
	int length = 0;
	int a, b;
	int check = 0;
	
	while (num != 0) {
		scanf("%d", &num);
		if (num == 0) return 0;
		length = 0;
		check = 0;

		tmpA = tmpB = num;
		while (num != 0) {
			num /= 10;
			length++;
		}
		num = tmpA;

		for (int i = 1; i <= length / 2; i++) {
			a = tmpA / pow(10, length - i); // 왼쪽 자리수를 구한다
			b = tmpB % (int)pow(10, i) / (int)pow(10, i - 1);  // 오른쪽 자리수를 구한다
	
			if (a == b) {
				tmpA -= pow(10, length - i) * a; 
				tmpB -= pow(10, i - 1) * b;
			}
			else {
				printf("no\n");
				check = 1;
				break;
			}
		}
		if(check == 0) printf("yes\n");
	}
}