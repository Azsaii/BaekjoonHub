#include <algorithm>
#include <vector>

#define ll long long

using namespace std;

int solution(vector<int> q1, vector<int> q2) {
    ll sum1 = 0;
    ll sum2 = 0;
    vector<int> q;
    for (const auto& i : q1) {
        q.push_back(i);
        sum1 += i;
    }
    for (const auto& i : q2) {
        q.push_back(i);
        sum2 += i;
    }
    ll avg = (sum1 + sum2) / 2;

    int s1 = 0;
    int s2 = q1.size();
    int e1 = s2;
    int e2 = 0;
    int sz = q.size();

    while (sum1 != avg && s1 < e1 && e1 < sz) {
        if (sum1 < avg) sum1 += q[e1++];
        if (sum1 > avg) sum1 -= q[s1++];
    }
    int ret = -1;
    if (sum1 == avg) {
        int ret1 = s1 + (e1 - s2);
        int ret2 = (e1 - s2) + (s1 - e2);
        ret = ret1 < ret2 ? ret1 : ret2;
    }
    return ret;
}