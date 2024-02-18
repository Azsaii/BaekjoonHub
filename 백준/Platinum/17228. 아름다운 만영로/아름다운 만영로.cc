#include<bits/stdc++.h>
#define OFFSET 'a'
#define EMPTY '\0'
#define SZ 26
#define BASE 127
#define MOD 998244353
#define pic pair<int, char>
using namespace std;
typedef long long ll;
vector<vector<pic>> vt;
vector<ll> vc;
int N, u, v, len, ret = 0;
char c;
string str;
ll target, power = 1;
void dfs(int cur) {
	if (vc.size() > str.size()) { // str 범위 벗어나는 뒷글자 삭제
		ll upd = (vc.back() - vc[vc.size() - len - 1] * power) % MOD;
		if (upd < 0) upd += MOD;
		if (upd == target) ret++;
	}
	for (auto& [ni, nc] : vt[cur]) { // 다음 문자 삽입
		vc.emplace_back((vc.back() * BASE + nc) % MOD);
		dfs(ni);
		vc.pop_back();
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N;
	vt.resize(N + 1);
	for (int i = 1; i < N; i++) {
		cin >> u >> v >> c;
		vt[u].emplace_back(make_pair(v, c));
	}
	cin >> str;
	len = str.length();
	for (int i = 0; str[i]; i++) {
		power = power * BASE % MOD; 
		target = (target * BASE + str[i]) % MOD; // 타겟 해시값
	}
	vc.push_back(0);
	dfs(1);
	cout << ret;
	return 0;
}