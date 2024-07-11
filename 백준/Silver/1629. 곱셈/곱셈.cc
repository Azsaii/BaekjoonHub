#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a, b, c;
ll f(ll x) {
    if (x == 0) return 1;
    if (x == 1) return a % c;
    ll t = f(x / 2) % c;
    if (x % 2 == 0) return t * t % c;
    return t * t % c * a % c;
}
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> a >> b >> c;
    // if(x % 2 == 0) -> a ^ x = a ^ (x / 2) * a ^ (x / 2)
    // else -> a ^ x = a ^ (x / 2) * a ^ (x / 2 + 1) * a
    cout << f(b);
}
