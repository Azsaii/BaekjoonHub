#include <string>
#include <vector>

using namespace std;

int solution(vector<int> v) {
    int ret = 0;
    int sz = v.size();

    for (int i = 0; i < sz - 2; i++) {
        for (int k = i + 1; k < sz - 1; k++) {
            for (int j = k + 1; j < sz; j++) {
                if (v[i] + v[k] + v[j] == 0) ret++;
            }
        }
    }
    
    return ret;
}