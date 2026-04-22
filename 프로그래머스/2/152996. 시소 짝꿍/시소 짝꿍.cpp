#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> v) {
    long long ret = 0;
    int sz = v.size();
    
    for (int i = 0; i < sz - 1; i++) {
        long long cnt = 1;
        for (int k = i + 1; k < sz; k++) {
            if (v[i] == v[k]) {
                cnt++;
                ret++;
                v[k] = v[sz - 1];
                v.pop_back();
                sz--;
                k--;
            }
        }
        for (int k = i + 1; k < sz; k++) {
            int a = v[i];
            int b = v[k];

            if (a > b) {
                int t = a;
                a = b;
                b = t;
            }

            if (a * 2 == b) ret += cnt;
            else if (a * 3 == b * 2) ret += cnt;
            else if (a * 4 == b * 3) ret += cnt;
        }
        ret += (cnt - 2) * (cnt - 1) / 2;
    }

    return ret;
}