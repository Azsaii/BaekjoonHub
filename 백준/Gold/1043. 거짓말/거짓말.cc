#include <bits/stdc++.h>
#define sz 51
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n, m, o, a, b, res = 0; cin >> n >> m >> o;
    bool map[sz] = {0, };
    vector<vector<int>> v1(sz), v2(sz);
    queue<int> q;
    for (int i = 0; i < o; i++) { cin >> b; map[b] = 1; q.push(b); }
    for (int i = 0; i < m; i++) {
        cin >> a;
        for (int j = 0; j < a; j++) {
            cin >> b;
            v1[i].push_back(b); v2[b].push_back(i);
        }
    }
    if (o == 0) { cout << m; return 0; }
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        for (int i : v2[top]) {
            for (int j : v1[i]) {
                if (!map[j]) {
                    map[j] = 1;
                    q.push(j);
                }
            }
        }
    }
    for (int i = 0; i < m; i++) {
        if (map[v1[i][0]]) continue;
        res++;
    }
    cout << res;
}