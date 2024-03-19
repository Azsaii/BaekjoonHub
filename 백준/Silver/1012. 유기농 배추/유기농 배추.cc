#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int T, M, N, K, x, y;
    int dx[4] = { 0 ,0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> M >> N >> K;
        vector<vector<int>> v(N, vector<int>(M, 0));
        vector<bool> vst(M * N, 0);
        queue<pii> q;
        int res = 1, cnt = 0;
        for (int i = 0; i < K; i++) { cin >> x >> y; v[y][x] = 1; }
        q.push({ y, x });
        vst[y * M + x] = 1;
        while(cnt != K) {
            while (!q.empty()) {
                auto [cy, cx] = q.front();
                q.pop();
                cnt++;
                if (cnt == K) break;
                for (int i = 0; i < 4; i++) {
                    int ny = cy + dy[i], nx = cx + dx[i], ni = ny * M + nx;
                    if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                    if (vst[ni] || !v[ny][nx]) continue;
                    vst[ni] = 1;
                    q.push({ ny, nx });
                }
            }
            if (cnt == K) break;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (!vst[i * M + j] && v[i][j]) {
                        vst[i * M + j] = 1;
                        q.push({i, j});
                        break; 
                    }
                }
                if (!q.empty()) break;
            }
            res++;
        }
        cout << res << '\n';
    }
    return 0;
}