#include <iostream>
using namespace std;
int main() {
	int num, h, w, n, res;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> h >> w >> n;
		if (n%h == 0) {
			res = n / h + h * 100;
		}
		else {
			res = n % h * 100 + n / h + 1;
		}
		cout << res << endl;
	}
	return 0;
}