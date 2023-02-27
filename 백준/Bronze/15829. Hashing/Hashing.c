#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int size = 0;
	char str[50];

	scanf("%d", &size);
	scanf("%s", str);

	int r = 31;
	int M = 1234567891;
	int res = 0;

	for (int i = 0; i < size; i++) {
		res += (str[i] - 96) * pow(r, i);
	}
	printf("%d", res % M);
}