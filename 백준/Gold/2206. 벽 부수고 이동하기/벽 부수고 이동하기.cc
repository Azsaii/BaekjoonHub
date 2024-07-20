#include <bits/stdc++.h>
#define pii pair<int, int>
#define ppp pair<pii, pii>
#define MAX 1000
using namespace std;
char v[MAX][MAX];
int dst[2][MAX][MAX];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            dst[0][i][j] = INT32_MAX, dst[1][i][j] = INT32_MAX;
        }
    }
    queue<ppp> q; q.push({ { 0, 0 }, { 1, 0 } }); dst[0][0][0] = 1;
    while (!q.empty()) {
        auto [c1, c2] = q.front();
        auto [cr, cc] = c1; auto [sum, mode] = c2;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = cr + dy[i], nc = cc + dx[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (mode == 0 && v[nr][nc] != '1' && dst[0][nr][nc] > sum + 1) {
                q.push({ {nr, nc}, {sum + 1, mode} });
                dst[0][nr][nc] = sum + 1;
            }
            else if (mode == 0 && v[nr][nc] == '1' && dst[0][nr][nc] > sum + 1) {
                q.push({ {nr, nc}, {sum + 1, 1} });
                dst[0][nr][nc] = sum + 1;
            }
            else if (mode == 1 && v[nr][nc] != '1' && dst[1][nr][nc] > sum + 1) {
                q.push({ {nr, nc}, {sum + 1, mode} });
                dst[1][nr][nc] = sum + 1;
            }
        }
    }
    int res = min(dst[0][n - 1][m - 1], dst[1][n - 1][m - 1]);
    if (res == INT32_MAX) cout << -1;
    else cout << res << '\n';
}