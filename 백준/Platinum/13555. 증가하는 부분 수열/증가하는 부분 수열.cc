#include<bits/stdc++.h>
#define MOD 5000000
#define MAX 100001
using namespace std;
typedef long long ll;
ll dp[MAX], ft[MAX];
int n, i, j, k, res = 0, arr[MAX];
void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}
ll sum(int p) {
    ll res = 0;
    while (p) {
        res = (res + ft[p]) % MOD;
        p -= p & -p;
    }
    return res;
}
void add(int p, ll v) {
    while (p <= MAX) {
        ft[p] = (ft[p] + v) % MOD;
        p += p & -p;
    }
}
int main() {
    init();
    cin >> n >> k;
    for (i = 1; i <= n; i++) {
        cin >> arr[i];
        dp[i] = 1;
    }
    for (i = 2; i <= k; i++) {
        memset(ft, 0, sizeof(ft));
        for (j = 1; j <= n; j++) {
            add(arr[j], dp[j]);
            dp[j] = sum(arr[j] - 1);
        } 
    }
    for (i = 1; i <= n; i++) res = (res + dp[i]) % MOD;
    cout << res;
}