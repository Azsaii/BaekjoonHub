#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        int t;
        for (int j = 1; j <= n; j++) {
            cin >> t;
            v[i][j] = t + v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
        }
    }
    int x1, y1, x2, y2;
    for (int i = 0; i < m; i++) {
        int res = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        res = v[x2][y2] - v[x1 - 1][y2] - v[x2][y1 - 1] + v[x1 - 1][y1 - 1];
        cout << res << '\n';
    }
}