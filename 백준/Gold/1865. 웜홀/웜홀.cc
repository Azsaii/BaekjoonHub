#include <bits/stdc++.h>
#define MAX 10000001
using namespace std;
int main() {
	int tc, a, b, c, d, e, f;
	cin >> tc;
	while (tc--) {
		cin >> a >> b >> c;
		vector<vector<int>> v;
		v.assign(a + 1, vector<int>(a + 1, MAX));
		while (b--) {
			cin >> d >> e >> f;
			if(v[d - 1][e - 1] > f) v[d - 1][e - 1] = f;
			if(v[e - 1][d - 1] > f) v[e - 1][d - 1] = f;
		}
		while (c--) {
			cin >> d >> e >> f;
			v[d - 1][e - 1] = f * -1;
		}
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < a; j++) {
				for (int k = 0; k < a; k++){
					int nv = v[i][j] + v[j][k];
					if (v[i][k] > nv) v[i][k] = nv;
				}
			}
		}
		bool ch = 0;
		for (int i = 0; i < a; i++) {
			if (v[i][i] < 0) {
				cout << "YES\n";
				ch = 1;
			}
			if (ch) break;
		}
		if (ch) continue;
		else cout << "NO\n";
	}
}