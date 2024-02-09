#include<bits/stdc++.h>
#define MAX 100001
using namespace std;
typedef long long ll;
ll ft[MAX];
int n, m, i, j, arr[MAX];
void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}
ll sum(int i) {
    ll ans = 0;
    while (i > 0) {
        ans += ft[i];
        i -= (i & -i);
    }
    return ans;
}
void upd(int i, int num) {
    while (i <= n) {
        ft[i] += num;
        i += i & -i;
    }
}
// Fenwick Tree Lazy propagation
int main() {
    init();
    cin >> n;
    arr[0] = 0;
    for (i = 1; i <= n; i++) {
        cin >> arr[i];
        upd(i, arr[i] - arr[i - 1]);
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