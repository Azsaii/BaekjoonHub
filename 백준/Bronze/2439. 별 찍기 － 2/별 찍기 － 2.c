#pragma warning(disable:4996)
#include<stdio.h>

int main() {
	int a;
	scanf("%d", &a);
	
	for (int i = 0; i < a; i++) {
		for (int j = a - i; j > 1; j--) {
			printf(" ");
		}
		for (int j = 0; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}
}
