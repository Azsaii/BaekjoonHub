#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    unordered_map<string, int> map1;
    size_t sz1 = want.size();
    for (size_t i = 0; i < sz1; i++) {
        map1[want[i]] = number[i];
    }

    int ret = 0;
    size_t sz2 = discount.size();
    for (size_t i = 0; i < sz2; i++) {
        unordered_map<string, int> map2;
        int comp = 0;
        int end = i + 10;
        if (end >= sz2) end = sz2;
        for (size_t k = i; k < end; k++) {
            string& key = discount[k];
            if (++map2[key] == map1[key]) comp++;
            if (comp == sz1) {
                ret++;
                break;
            }
        }
    }
    return ret;
}