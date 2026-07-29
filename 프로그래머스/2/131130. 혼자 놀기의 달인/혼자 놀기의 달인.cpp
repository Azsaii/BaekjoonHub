#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cards) {
    int sz = cards.size();
    vector<bool> v(sz, 0);
    vector<int> ret;
    for (int i = 0; i < sz; i++) {
        if (v[i] == true) continue;
        int cnt = 0;
        int cur = i;
        while (v[cur] == false) {
            v[cur] = true;
            cnt++;
            cur = cards[cur] - 1;
        }
        ret.push_back(cnt);
    }
    if(ret.size() == 1) return 0;
    
    sort(ret.begin(), ret.end(), greater<int>());
    return ret[0] * ret[1];
}