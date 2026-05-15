#include <vector>
#define ll long long

using namespace std;

vector<long long> solution(vector<ll> nums) {
    vector<ll> ret;
    for (const auto& i : nums) {
        if (i % 2 == 0) ret.push_back(i + 1);
        else {
            ll t = 2;
            while (i & t) t <<= 1;
            t >>= 1;
            ret.push_back(i + t);
        }
    }
    return ret;
}