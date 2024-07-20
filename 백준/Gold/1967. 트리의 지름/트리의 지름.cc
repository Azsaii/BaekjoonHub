#include <bits/stdc++.h>
#define pss pair<short, short>
using namespace std;
vector<vector<pss>> v(10001);
int res = 0;
int dfs(int x) {
    int maxv = 0;
    for (auto [nc, nv] : v[x]) {
        int cur = dfs(nc) + nv + maxv;
        res = max(res, cur);
        maxv = max(maxv, cur - maxv);
    }
    return maxv;
}
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n, a, b, c; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> c;
        v[a].push_back({ b, c });
    }
    dfs(1);
    cout << res;
}