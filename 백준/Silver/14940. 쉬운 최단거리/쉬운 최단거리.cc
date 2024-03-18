#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n, m, x, y;
    int dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m, -1)), res(n, vector<int>(m, -1));
    vector<bool> vst(n * m + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            if (v[i][j] == 2) { y = i; x = j; }
            if (v[i][j] == 0) { res[i][j] = 0; vst[i * m + j] = 1; }
        }
    }
    queue<pii> q;
    q.push({ y, x });
    res[y][x] = 0;
    vst[y * m + x] = 1;
    while(!q.empty()) {
        int cy = q.front().first, cx = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i], ni = ny * m + nx;
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (vst[ni] == 1) continue;
            vst[ni] = 1;
            q.push({ ny, nx });
            res[ny][nx] = res[cy][cx] + 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << res[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}