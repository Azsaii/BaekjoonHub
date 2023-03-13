#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int size = 0;
	int tmp = 0;
	int arr[10001] = {0,};

	scanf("%d", &size);
	
	for (int i = 0; i < size; i++) {
		scanf("%d", &tmp);
		arr[tmp]++;
	}


	for (int i = 1; i <= 10000; i++) { 
		for (int k = 0; k < arr[i]; k++) {
			printf("%d\n", i);
		}
	}
}
