#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> v) {
    vector<int> ret;
    int sz = v.size();
    
    for(int i = 0; i < sz - 1; i++) {
        for(int k = i + 1; k < sz; k++){
            int sum = v[i] + v[k];
            auto it = find(ret.begin(), ret.end(), sum);
            if(it == ret.end()) ret.push_back(sum);
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}