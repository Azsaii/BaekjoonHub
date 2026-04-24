#include <vector>
#include <iostream>
using namespace std;

bool calc(int a) {
    for (int i = 2; i < a; i++) {
        if (a % i == 0) return false;
    }
    
    return true;
}

int solution(vector<int> v) {
    int sz = v.size();
    int ret = 0;
    for (int i = 0; i < sz - 2; i++) {
        for (int k = i + 1; k < sz - 1; k++) {
            for (int j = k + 1; j < sz; j++) {
                ret += calc(v[i] + v[k] + v[j]);
            }
        }
    }
    return ret;
}