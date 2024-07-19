#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n, m, a, b, c; cin >> n >> m;
    vector<vector<ll>> v(n + 1, vector<ll>(n + 1, INT32_MAX));
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if(v[a][b] > c) v[a][b] = c; 
        v[a][a] = 0;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                ll nv = v[i][k] + v[k][j];
                if (v[i][j] > nv) v[i][j] = nv;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(v[i][j] != INT32_MAX) cout << v[i][j] << ' ';
            else cout << "0 ";
        }
        cout << '\n';
    }
}