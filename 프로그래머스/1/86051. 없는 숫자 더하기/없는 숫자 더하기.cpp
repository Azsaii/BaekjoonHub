#include <string>
#include <vector>

using namespace std;

int solution(vector<int> v) {
    int ret = 0;
    for(int i : v){
        ret += i;
    }
    return 45 - ret;
}