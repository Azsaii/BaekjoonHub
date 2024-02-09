#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> v;
vector<ll> ft;
int n, m, i, j;
ll sum(int i) {
    ll ans = 0;
    while (i > 0) {
        ans += ft[i];
        i -= (i & -i);
    }
    return ans;
}
void upd(int p, int num) {
    while (p <= n) {
        ft[p] += num;
        p += p & -p;
    }
}
// Fenwick Tree Lazy propagation
int main() {
    cout.tie(0); cin.tie(0); ios_base::sync_with_stdio(false);
    cin >> n;
    v.resize(n + 1, 0);
    ft.resize(n + 1, 0);
    for (i = 1; i <= n; i++) {
        cin >> v[i];
        ft[i] = v[i] - v[i - 1];
    }
    for (i = 1; i <= n; i++) {
        if (i + (i & -i) > n) continue;
        ft[i + (i & -i)] += ft[i];
    }
    cin >> m;
    for (i = 0; i < m; i++) {
        int k, a, b, c;
        cin >> k >> a;
        if (k & 1) {
            cin >> b >> c;
            upd(a, c);
            upd(b + 1, -c);
        }
        else cout << sum(a) << '\n';
    }
}