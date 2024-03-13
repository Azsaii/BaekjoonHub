#include<bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	int N, M, res = 0, cnt = 0; 
	cin >> N;
	vector<int> cv(N);
	for (int i = 0; i < N; i++) cin >> cv[i];
	cin >> M;
	sort(cv.rbegin(), cv.rend());
	vector<int> bv(M);
	bool ch = 0;
	for (int i = 0; i < M; i++) {
		cin >> bv[i];
		if (bv[i] > cv[0]) ch = 1;
	}
	if (ch) { cout << "-1"; return 0; }
	sort(bv.rbegin(), bv.rend());
	for (int i = 0; i < N; i++) {
		if (cv[i] < bv[M - 1]) { N = i; break; }
	}
	int lim = 0;
	for (int i = 0; i < M; i++) {
		if (cv[N - 1] >= bv[i]) { lim = i; break; }
	}
	int am = lim;
	while (cnt < lim) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < am; j++) {
				if (cv[i] >= bv[j]) { bv.erase(bv.begin() + j); cnt++; am--; break; }
			}
		}
		res++;
	}
	int o = M - (res * N);
	if (o > 0) o = (o % N == 0) ? o / N : o / N + 1;
	else o = 0;
	res += o;
	cout << res;
	return 0;
}