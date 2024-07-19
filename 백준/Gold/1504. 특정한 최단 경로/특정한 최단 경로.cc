#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n, e, a, b, c, v1, v2; cin >> n >> e;
    vector<vector<ll>> v(n + 1, vector<ll>(n + 1, INT32_MAX));
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        v[a][b] = c; v[b][a] = c;
        v[a][a] = 0; v[b][b] = 0;
    }
    cin >> v1 >> v2;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                ll nv = v[i][k] + v[k][j];
                if (v[i][j] > nv) {
                    v[i][j] = nv;
                }
            }
        }
    }
    ll r1 = v[1][v1] + v[v1][v2] + v[v2][n];
    ll r2 = v[1][v2] + v[v2][v1] + v[v1][n];
    ll minv = min(r1, r2);
    if (minv <= INT32_MAX) cout << minv;
    else cout << -1;
}