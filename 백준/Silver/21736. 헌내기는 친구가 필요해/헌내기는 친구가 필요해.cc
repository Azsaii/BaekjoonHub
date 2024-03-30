#include <bits/stdc++.h>
#define NUM 601
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int N, M, res = 0;
    int dy[4] = { 0, 0, 1, -1 }, dx[4] = { 1, -1, 0, 0 };
    char c;
    cin >> N >> M;
    char v[NUM][NUM], vst[NUM][NUM] = { 0, };
    pair<int, int> cur;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> c;
            if (c == 'I') cur = { i, j };
            v[i][j] = c;
        }
    }
    queue<pair<int, int>> q;
    q.push(cur); vst[cur.first][cur.second] = 1;
    while (!q.empty()) {
        int cy = q.front().first, cx = q.front().second;
        if (v[cy][cx] == 'P') res++;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i], nx = cx + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (v[ny][nx] != 'X' && vst[ny][nx] != 1) {
                vst[ny][nx] = 1;
                q.push({ ny, nx });
            }
        }
    }
    res != 0 ? cout << res : cout << "TT";
    return 0;
}