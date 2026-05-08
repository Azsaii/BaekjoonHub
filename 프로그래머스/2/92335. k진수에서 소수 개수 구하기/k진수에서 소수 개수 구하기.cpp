#include <string>
#include <vector>
#include <cmath>
#define ll long long

using namespace std;

bool checkPrime(ll a) {
	bool ch = true;
	ll sq = sqrt(a);
	for (ll i = 2; i <= sq; i++) {
		if (a % i == 0) {
			ch = false;
			break;
		}
	}
	return ch;
}

int solution(int n, int k) {
    int ret = 0;
    ll sum = 0;
    ll mul = 1;
    while (n) {
        int t = n % k;
        if (t == 0) {
            if (sum == 2 || sum == 3) ret++;
            else if (sum > 4 && checkPrime(sum)) ret++;
            sum = 0;
            mul = 1;
        }
        else {
            sum += t * mul;
            mul *= 10;
        }
        n /= k;
    }
    if (sum > 1 && checkPrime(sum)) ret++;
    return ret;
}