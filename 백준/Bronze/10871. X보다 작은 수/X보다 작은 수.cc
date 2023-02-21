#pragma warning(disable:4996)
#include<stdio.h>

int main() {
	int n[10000];
	int size;
	int x;
	scanf("%d %d", &size, &x);

	for (int i = 0; i < size; i++) {
		scanf("%d", &n[i]);
		if (n[i] < x) printf("%d ", n[i]);
	}
}