#include <string>
#include <vector>

using namespace std;

int solution(int a, int d, vector<bool> included) {
    int ret = 0;
    int sz = included.size();
    for(int i = 0; i < sz; i++){
        if(included[i]) ret += a + d * i;
    }
    return ret;
}