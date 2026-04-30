#include <string>
#include <vector>
#define ll long long
using namespace std;

vector<ll> v(1234567, -1);

ll calc(ll t) {
    if (t == 0) return 0;
    else if (t == 1) return 1;
    else {
        ll a = v[t - 1];
        ll b = v[t - 2];
        if (a == -1) {
            a = calc(t - 1);
            v[t - 1] = a;
        }
        if (b == -1) {
            b = calc(t - 2);
            v[t - 2] = b;
        }

        ll ret = (a + b) % 1234567;
        v[t] = ret;
        return ret;
    }
}

long long solution(int n) {
    ll ret = calc(n + 1);
    return ret;
}