#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> ret;
    vector<int> v;
    size_t sz = progresses.size();
    for (size_t i = 0; i < sz; i++) {
        int day = (100 - progresses[i]) / speeds[i];
        if ((100 - progresses[i]) % speeds[i] != 0) day++;
        v.push_back(day);
    }
    int cur = v[0];
    int cnt = 0;
    for (size_t i = 0; i < sz; i++) {
        if (v[i] <= cur) cnt++;
        else {
            ret.push_back(cnt);
            cur = v[i];
            cnt = 0;
            i--;
        }
    }
    if (cnt != 0) ret.push_back(cnt);
    return ret;
}