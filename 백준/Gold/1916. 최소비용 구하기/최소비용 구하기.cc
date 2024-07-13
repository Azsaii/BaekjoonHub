#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n, m, val, s, e;
    cin >> n >> m;
    vector<vector<pii>> v(n + 1);
    vector<int> dst(n + 1, INT32_MAX);
    for (int i = 0; i < m; i++) {
        cin >> s >> e >> val;
        v[s].push_back({ val, e });
    }
    cin >> s >> e;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({ 0, s });
    dst[s] = 0;
    while (!q.empty()) {
        auto [cv, ci] = q.top();
        q.pop();
        //cout << "ci: " << ci << ", cv: " << cv << '\n';
        if (cv > dst[ci]) continue;
        for (pii np : v[ci]) {
            //cout << "np.f: " << np.first << ", s: " << np.second << '\n';
            int nc = dst[ci] + np.first;
            //cout << "nc: " << nc << '\n';
            if (nc < dst[np.second]) {          
                dst[np.second] = nc;
                //cout << "dst[" << np.second << "] = " << nc << '\n';
                q.push(np);
            }
        }
    }
    cout << dst[e];
}