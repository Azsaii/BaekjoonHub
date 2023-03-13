#include <iostream>
using namespace std;
int main() {
	int n, res = 1;
	cin >> n;
	int i = 2, j = 7;
	if (n != 1) {
		while (n<i || n>j) {
			i = i + 6 * res;
			j = j + 6 * (res + 1);
			res++;
		}
		res++;
	}
	cout << res;
	return 0;
}
