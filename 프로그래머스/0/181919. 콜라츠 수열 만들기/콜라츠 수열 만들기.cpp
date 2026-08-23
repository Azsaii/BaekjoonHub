#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> ret;
    while(n != 1){
        ret.push_back(n);
        if(n % 2 == 0) n /= 2;
        else n = 3 * n + 1;
    }
    ret.push_back(1);
    return ret;
}