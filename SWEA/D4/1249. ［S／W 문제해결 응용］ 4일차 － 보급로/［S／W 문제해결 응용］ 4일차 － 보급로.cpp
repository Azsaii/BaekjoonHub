#include<iostream>
#include<vector>
#include<queue>
#define pii pair<int, int>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n;
    char temp;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cin >> n;
        int sz = n * n;
        vector<int> arr(sz), dist(sz, INT32_MAX);
        vector<bool> v(sz, 0);
        queue<pii> q;
        int left[4] = { -1, 1, -n, n };
        int right[4] = { n, sz, n, n };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> temp;
                arr[i * n + j] = temp - '0';
            }
        }
        q.push({ 0, 0 });
        while (!q.empty()) {
            pii cur = q.front();
            q.pop();
            int f = cur.first, s = cur.second;
            if (v[f] && dist[f] > arr[f] + s)continue;
            v[f] = 1;
            if ((f + 1) % n != 0 && dist[f + 1] > arr[f + 1] + s) { // 우
                dist[f + 1] = arr[f + 1] + s;
                q.push({ f + 1, arr[f + 1] + s });
            }   
            if ((f + n) < sz && dist[f + n] > arr[f + n] + s) { // 하
                dist[f + n] = arr[f + n] + s;
                q.push({ f + n, arr[f + n] + s });
            }    
            if (f % n != 0 && dist[f - 1] > arr[f - 1] + s) { // 좌
                dist[f - 1] = arr[f - 1] + s;
                q.push({ f - 1, arr[f - 1] + s });
            }   
            if (f >= n && dist[f - n] > arr[f - n] + s) { // 상
                dist[f - n] = arr[f - n] + s;
                q.push({ f - n, arr[f - n] + s });
            }
        }
        cout << "#" << tc << ' ' << dist[sz - 1] << '\n';
    }
    return 0;
}