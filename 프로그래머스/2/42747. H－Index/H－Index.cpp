#include <string>
#include <vector>

using namespace std;

int solution(vector<int> v) {
    int ret = 0;
    size_t sz = v.size();
    for (size_t i = 0; i < sz; i++) {
        int up = 0;
        int down = 0;
        int cur = v[i];
        for (size_t k = 0; k < sz; k++) {
            if (v[k] >= cur) up++;
            else down++;
        }
        if (up >= cur && down <= cur && ret < cur) ret = cur;
        else if (up < cur && down <= up && ret < up) ret = up;
    }
    return ret;
}