#include <bits/stdc++.h>
#define ll long long
#define pli pair<ll, int>
using namespace std;
int n;
vector<vector<ll>> v;
vector<ll> dst;
void dij(int x) {
    for (int i = 1; i <= n; i++) dst[i] = INT32_MAX;
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    dst[x] = 0;
    pq.push({ 0, x });
    while (!pq.empty()) {
        auto [cv, cn] = pq.top();
        pq.pop();
        if (cv > dst[cn]) continue;
        for (int i = 1; i <= n; i++) {
            ll nv = cv + v[cn][i];
            if (dst[i] > nv) {
                dst[i] = nv;
                pq.push({ nv, i });
            }
        }
    }
}
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int e, a, b, c, v1, v2; cin >> n >> e;
    v.assign(n + 1, vector<ll>(n + 1, INT32_MAX));
    dst.resize(n + 1);
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        v[a][b] = c; v[b][a] = c;
        v[a][a] = 0; v[b][b] = 0;
    }
    cin >> v1 >> v2;
    dij(v1);
    ll r1 = dst[1] + dst[v2];
    ll r2 = dst[n];
    if (r1 >= INT32_MAX && r2 >= INT32_MAX) { cout << -1; return 0; }
    dij(v2);
    r1 += dst[n];
    r2 += dst[1] + dst[v1];
    if (r1 >= INT32_MAX && r2 >= INT32_MAX) { cout << -1; return 0; }
    cout << min(r1, r2);
}