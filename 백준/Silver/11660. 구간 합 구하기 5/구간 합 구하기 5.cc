#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        int total = 0, t;
        for (int j = 0; j < n; j++) {
            cin >> t;
            total += t;
            v[i][j] = total;
        }
    }
    int x1, y1, x2, y2;
    for (int i = 0; i < m; i++) {
        int res = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;
        for (int j = x1; j <= x2; j++) {
            res += v[j][y2];
            if (y1 != 0) res -= v[j][y1 - 1];
        }
        cout << res << '\n';
    }
}