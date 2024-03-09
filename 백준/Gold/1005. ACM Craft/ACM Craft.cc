#include<bits/stdc++.h>
using namespace std;
vector<int> tv, save;
vector<vector<int>> g;
int sum = 0;
void dfs(int x) {
	save[x] = tv[x];
	int maxv = 0;
	for (int i : g[x]) {
		if (save[i] == -1) dfs(i);
		maxv = max(maxv, save[i]);
	}
	save[x] += maxv;
}
int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int tc = 0; tc < T; ++tc) {
		int N, K, a, b, target, res = 0;
		cin >> N >> K;
		tv.clear(); tv.resize(N + 1);
		save.clear(); save.resize(N + 1, -1);
		g.clear(); g.resize(N + 1);
		for (int i = 1; i <= N; i++) cin >> tv[i];
		for (int i = 0; i < K; i++) {
			cin >> a >> b;
			g[b].push_back(a);
		}
		cin >> target;
		dfs(target);
		cout << save[target] << '\n';
	}
	return 0;
}