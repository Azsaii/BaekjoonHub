#include <string>
#include <vector>

using namespace std;

int solution(vector<int> v1, vector<bool> v2) {
    int ret = 0;
    int sz = v1.size();
    for(int i = 0; i < sz; i++){
        int t = v1[i];
        if(v2[i] == false) t *= -1;
        ret += t;
    }
    return ret;
}