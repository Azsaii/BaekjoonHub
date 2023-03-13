#include<stdio.h>

int main() {
	int a[10];

	for (int i = 0; i < 8; i++) {
		if(i != 7) scanf("%d ", &a[i]);
		else scanf("%d", &a[i]);
	}

	for (int i = 0; i < 7; i++) {
		if (a[i] - a[i + 1] > 1 || a[i] - a[i + 1] < -1 || a[i] == a[i + 1]) {
			printf("mixed");
			return 0;
		}
	}

	if (a[0] < a[1]) printf("ascending");
	else if (a[0] > a[1]) printf("descending");
}
