#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> ret;
    if(n > m) swap(n, m);
    
    for(int i = n; i >= 1; i--){
        if(n % i == 0 && m % i == 0){
            ret.push_back(i);
            break;
        }
    }
    
    int maxv = n * m;
    if(ret[0] == 1){
        ret.push_back(maxv);
    }
    else {
        for(int i = m; i <= maxv; i += m){
            if(i % n == 0){
                ret.push_back(i);
                break;
            }
        }
    }
    return ret;
}
