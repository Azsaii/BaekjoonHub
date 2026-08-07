#include <cmath>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int ret = 0;
    int s1 = 1;
    int s2 = 0;
    for(const auto& i : num_list){
        s1 *= i;
        s2 += i;
    }
    if(s1 < pow(s2, 2)) ret = 1;
    return ret;
}