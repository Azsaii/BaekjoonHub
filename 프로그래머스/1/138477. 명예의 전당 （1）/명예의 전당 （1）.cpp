#include <algorithm>
#include <vector>

using namespace std;

bool Comp(const int& a, const int& b) {
    return a > b;
}

vector<int> solution(int k, vector<int> v) {
    vector<int> ret;
    vector<int> tmp;
    int sz = v.size();
    if(sz < k) k = sz;
    
    for (int i = 0; i < k; i++) {
        tmp.push_back(v[i]);
        sort(tmp.begin(), tmp.end(), Comp);
        ret.push_back(tmp[i]);
    }
   
    for (int i = k; i < sz; i++) {
        tmp.push_back(v[i]);
        sort(tmp.begin(), tmp.end(), Comp);
        ret.push_back(tmp[k - 1]);
        tmp.pop_back();
    }
    return ret;
}