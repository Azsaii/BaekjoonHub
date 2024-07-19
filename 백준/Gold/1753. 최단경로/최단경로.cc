#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int a, b, c, d, e, f; cin >> a >> b >> c;
    vector<vector<pii>> v(20001);
    vector<int> dst(20001, INT32_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 0; i < b; i++) {
        cin >> d >> e >> f;
        v[d].push_back({ f, e });
        if (d == c) { 
            if(dst[e] > f) dst[e] = f; 
            pq.push({ f, e }); 
        }
    }
    dst[c] = 0;
    while (!pq.empty()) {
        auto [cv, cn] = pq.top();
        pq.pop();
        if (cv > dst[cn]) continue;
        for (auto [nv, nn] : v[cn]) {
            int newv = cv + nv;
            if (dst[nn] > newv){
                dst[nn] = newv;
                pq.push({ newv, nn });
            }
        }
    }
    for (int i = 1; i <= a; i++) {
        if (i == c) { cout << "0\n"; continue; }
        if (dst[i] == INT32_MAX) cout << "INF\n";
        else cout << dst[i] << '\n';
    }
}