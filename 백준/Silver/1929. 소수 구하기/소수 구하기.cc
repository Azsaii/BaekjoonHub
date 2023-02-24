#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int a = 0, b = 0;
	int k = 2;
	int* arr;
	scanf("%d %d", &a, &b);

	arr = (int*)malloc(sizeof(int) * (b + 1));

	for (int i = 0; i <= b; i++) arr[i] = 1;

	for (int i = 2; i <= sqrt(b); i++) {
		if (arr[i]) {
			k = 2;
			while (i * k <= b) {
				arr[i * k] = 0;
				k++;
			}
		}
	}
	for (int i = a; i <= b; i++) {
		if (arr[i] && i != 1) printf("%d\n", i);
	}

	free(arr);
}