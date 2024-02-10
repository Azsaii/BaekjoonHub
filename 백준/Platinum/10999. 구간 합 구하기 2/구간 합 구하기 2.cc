#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> deg, con;
int n, m, k, i, j;
void init() {
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(false);
}
void initTree() {
    for (int p = 1; p <= n; p++) {
        if (p + (p & -p) > n) continue;
        con[p + (p & -p)] += con[p];
    }
}
ll sum(vector<ll>& ft, int p) {
    ll ret = 0;
    for (; p > 0; p -= p & -p) ret += ft[p];
    return ret;
}
void upd(vector<ll>& ft, int p, ll num) {
    for (; p <= n; p += p & -p) ft[p] += num;
}
int main() {
    init();
    cin >> n >> m >> k;
    deg.resize(n + 1, 0);
    con.resize(n + 1, 0);
    for (i = 1; i <= n; i++) cin >> con[i];
    initTree();
    int j = m + k;
    for (i = 0; i < j; i++) {
        ll o, l, r, x;
        cin >> o >> l >> r;
        if (o & 1) { 
            cin >> x;
            upd(deg, l, x); upd(deg, r + 1, -x); // 1차
            upd(con, l, (1 - l) * x); upd(con, r + 1, r * x); // 상수
        }
        else {
            ll res = sum(deg, r) * r + sum(con, r);
            cout << res - (sum(deg, l - 1) * (l - 1) + sum(con, l - 1)) << '\n';
        }
    }
}