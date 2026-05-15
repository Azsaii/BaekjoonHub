#include <vector>
#define ll long long

using namespace std;

vector<long long> solution(vector<ll> nums) {
    vector<ll> ret;
    for (const auto& i : nums) {
        if (i % 2 == 0) ret.push_back(i + 1);
        else {
            ll cnt = 0;
            ll tmp = i;
            while (tmp > 0) {
                cnt++;
                tmp >>= 1;
                if (tmp % 2 == 0) break;
            }
            tmp = 1;
            ret.push_back(i + ((tmp << cnt) - (tmp << (cnt - 1))));
        }
    }
    return ret;
}