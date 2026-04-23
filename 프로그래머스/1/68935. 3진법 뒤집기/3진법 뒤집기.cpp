#include <cmath>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int > v;

    while(n){
        v.push_back(n % 3);
        n /= 3;
    }

    int ret = 0;
    int k = 0;
    int sz = v.size() - 1;
    for (int i = sz; i >= 0; i--) {
        ret += pow(3, k++) * v[i];
    }
    
    return ret;
}