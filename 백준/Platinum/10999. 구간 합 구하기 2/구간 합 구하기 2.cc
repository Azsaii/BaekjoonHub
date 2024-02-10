#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> tree, deg, con;
ll n, m, k, i, t;
void init() {
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(false);
}
ll sum(vector<ll>& ft, ll p) {
    ll ret = 0;
    for (; p > 0; p -= p & -p) ret += ft[p];
    return ret;
}
void upd(vector<ll>& ft, ll p, ll num) {
    for (; p <= n; p += p & -p) ft[p] += num;
}
int main() {
    init();
    cin >> n >> m >> k;
    tree.resize(n + 1, 0);
    deg.resize(n + 1, 0);
    con.resize(n + 1, 0);
    for (i = 1; i <= n; i++) {
        cin >> t;
        upd(tree, i, t);
    }
    for (i = 0; i < m + k; i++) {
        ll o, l, r, x;
        cin >> o >> l >> r;
        if (l > r) swap(l, r);
        if (o & 1) { 
            cin >> x;
            upd(deg, l, x);
            upd(deg, r + 1, -x);
            upd(con, l, (1 - l) * x);
            upd(con, r + 1, r * x);
        }
        else {
            ll res = 0;
            res += sum(deg, r)* r + sum(con, r);
            res -= sum(deg, l - 1) * (l - 1) + sum(con, l - 1);
            res += sum(tree, r) - sum(tree, l - 1);
            cout << res << '\n';
        }
    }
}