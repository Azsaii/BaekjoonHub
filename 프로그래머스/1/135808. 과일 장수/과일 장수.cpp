#include <algorithm>
#include <vector>

using namespace std;

int solution(int k, int m, vector<int> v) {
    sort(v.rbegin(), v.rend());
    int sz = v.size();
    sz -= sz % m;

    int ret = 0;
    for (int i = 0; i < sz;) {
        ret += v[i + m - 1] * m;
        i += m;
    }
    
    return ret;
}