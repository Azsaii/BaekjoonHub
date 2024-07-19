#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n, m, r, a, b, c; cin >> n >> m >> r;
    vector<int> item(n + 1);
    vector<vector<ll>> v(n + 1, vector<ll>(n + 1, INT32_MAX));
    for (int i = 1; i <= n; i++) cin >> item[i];
    for (int i = 0; i < r; i++) {
        cin >> a >> b >> c;
        v[a][b] = c; v[b][a] = c;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                ll nv = v[i][k] + v[k][j];
                if (v[i][j] > nv) v[i][j] = nv;
            }
        }
    }
    int maxv = 0;
    for (int i = 1; i <= n; i++) {
        int sum = item[i];
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (v[i][j] <= m) sum += item[j];
        }
        maxv = max(maxv, sum);
    }
    cout << maxv;
}