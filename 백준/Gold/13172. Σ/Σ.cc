#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
ll gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
ll mp(ll b, ll e) {
    ll res = 1;
    b %= MOD;
    while (e > 0) {
        if (e & 1) res = (res * b) % MOD;
        b = (b * b) % MOD;
        e >>= 1;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    ll a = 0, b = 0, res = 0; 
    for (int i = 0; i < n; i++) {
        cin >> b >> a;
        ll r = gcd(a, b);
        a /= r, b /= r;
        res += a * mp(b, MOD - 2) % MOD;
        res %= MOD;
    }
    cout << res;
}