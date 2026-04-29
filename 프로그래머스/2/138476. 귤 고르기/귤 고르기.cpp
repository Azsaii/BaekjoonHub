#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tang) {
    unordered_map<int, int> map;
    vector<int> cnt;

    size_t sz = tang.size();
    for (int i = 0; i < sz; i++) {
        if (map.find(tang[i]) == map.end()) {
            map[tang[i]] = cnt.size();
            cnt.push_back(1);
        }
        else {
            cnt[map[tang[i]]]++;
        }
    }

    sort(cnt.begin(), cnt.end(), [](const int& a, const int& b) {
        return a > b;
        });
    
    int ret = 1;
    for (const int& i : cnt) {
        k -= i;
        if (k <= 0) break;
        ret++;
    }
    
    return ret;
}