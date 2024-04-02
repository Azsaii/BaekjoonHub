#include <bits/stdc++.h>
using namespace std;
#define NUM 26
#define pii pair<int, int>
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int N, cnt = 0, v[NUM][NUM], ii = 0;
    int dy[4] = { 0, 0, 1, -1 }, dx[4] = { 1, -1, 0, 0 };
    string str;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> str;
        for (int j = 0; j < N; j++) {
            v[i][j] = str[j] - '0';
            if (str[j] - '0' == 1) cnt++;
        }
    }
    vector<int> res;
    bool vst[NUM][NUM] = { 0, };
    queue<pii> q;
    while (cnt) {
        int sum = 1;
        pii start = { -1, -1 };
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (v[i][j] == 1 && vst[i][j] == 0) {
                    vst[i][j] = 1;
                    start = { i, j };
                    break;
                }
            }
            if (start.first != -1) break;
        }
        if (start.first != -1) q.push(start);
        else break;
        while (!q.empty()) {
            int cy = q.front().first, cx = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int ny = cy + dy[i], nx = cx + dx[i];
                if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                if (v[ny][nx] == 0) continue;
                if (vst[ny][nx] == 0) {
                    vst[ny][nx] = 1;
                    q.push({ ny, nx });
                    sum++;
                }
            }
        }
        cnt -= sum;
        res.push_back(sum);
    }
    cout << res.size() << '\n';
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) cout << res[i] << '\n';
}