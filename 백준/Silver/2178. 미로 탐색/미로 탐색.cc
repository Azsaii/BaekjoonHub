#include <bits/stdc++.h>
#define INF 99999
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int N, M;
    int dy[4] = { 0, 0, 1, -1 }, dx[4] = { 1, -1, 0, 0 };
    char c;
    cin >> N >> M;
    vector<vector<char>> v(N);
    vector<vector<int>> dist(N, vector<int>(M, N * M + 1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> c;
            v[i].push_back(c);
        }
    }
    queue<pair<int, int>> q;
    q.push({ 0, 0 }); dist[0][0] = 1;
    while (!q.empty()) {
        int cy = q.front().first, cx = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i], nx = cx + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (v[ny][nx] == '1') {
                int nv = dist[ny][nx], cv = dist[cy][cx];
                if (nv > cv + 1) {
                    dist[ny][nx] = cv + 1;
                    q.push({ ny, nx });
                } 
            }
        }
    }
    cout << dist[N - 1][M - 1];
    return 0;
}