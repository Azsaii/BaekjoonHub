#include <iostream>
#include <algorithm>
using namespace std;
#define pii pair<int, int>

int main() {

	int N, a, b, c;
	cin >> N;

	pii v[3] = { {0, 0}, {0, 0}, {0, 0} };

	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;

		int minv1 = min({ v[0].first, v[1].first});
		int minv2 = min({ minv1, v[2].first });
		int minv3 = min({ v[1].first, v[2].first });

		v[0].first = minv1 + a;
		v[1].first = minv2 + b;
		v[2].first = minv3 + c;

		int maxv1 = max({ v[0].second, v[1].second });
		int maxv2 = max({ maxv1, v[2].second });
		int maxv3 = max({ v[1].second, v[2].second });

		v[0].second = maxv1 + a;
		v[1].second = maxv2 + b;
		v[2].second = maxv3 + c;
	}

	cout << max({ v[0].second, v[1].second, v[2].second }) << ' ' << min({ v[0].first, v[1].first, v[2].first });
}