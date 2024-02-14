#include<iostream>
#include<vector>
#include<queue>
#define pii pair<int, int>
using namespace std;
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
int arr[100][100];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n;
    char temp;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cin >> n;
        int sz = n * n;
        int dist[100][100] = { 0, };
        bool v[100][100] = { 0, };
        queue<pii> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> temp;
                arr[i][j] = temp - '0';
            }
        }
        q.push({ 0, 0 });
        while (!q.empty()) {
            pii cur = q.front();
            q.pop();
            int cy = cur.first, cx = cur.second;
            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i], ny = cy + dy[i];
                if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                if (!v[ny][nx] || dist[ny][nx] > dist[cy][cx] + arr[ny][nx]) {
                    dist[ny][nx] = dist[cy][cx] + arr[ny][nx];
                    q.push({ ny, nx });
                    v[ny][nx] = 1;
                }
            }
        }
        cout << "#" << tc << ' ' << dist[n - 1][n - 1] << '\n';
    }
    return 0;
}