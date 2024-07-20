#include <bits/stdc++.h>
#define pss pair<short, short>
using namespace std;
vector<vector<pss>> v;
int res = 0;
int dfs(int x) {
    int maxv = 0, s1 = 0, s2 = 0;
    for (auto [nc, nv] : v[x]) {
        int nxt = dfs(nc) + nv;
        if (s1 < nxt) { s2 = s1; s1 = nxt; }
        else if (s2 < nxt) s2 = nxt;
        maxv = max(maxv, nxt);
    }
    res = max(res, s1 + s2);
    return maxv;
}
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n, a, b, c; cin >> n;
    v.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> c;
        v[a].push_back({ b, c });
    }
    dfs(1);
    cout << res;
}