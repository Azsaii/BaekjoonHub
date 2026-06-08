#include <cmath>
#include <vector>
#define ll long long
using namespace std;

ll solution(int k, int d) {
    ll lk = static_cast<ll>(k);
    ll ld = static_cast<ll>(d);
    ll p = ld * ld;
    ll ret = 0;
    for (ll i = 0; i <= ld; i += k) {	
        ret += static_cast<ll>(sqrt(p - i * i)) / lk + 1;
    }
    return ret;
}