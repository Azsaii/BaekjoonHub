#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int size = 0;
	char str[50] = {'0', };

	scanf("%d", &size);
	scanf("%s", str);

	int M = 1234567891;
	int r = 31;
	unsigned long long int rtmp = 1;
	unsigned long long int res = 0;

	for (int i = 0; i < size; i++) {		
		if(i != 0) rtmp *= r;
		rtmp %= M;
		res += (str[i] - 96) * rtmp;
		res %= M;
	}
	printf("%d", res);
}
