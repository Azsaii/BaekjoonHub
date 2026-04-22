#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> orig){
    vector<int> v;
    int minv = orig[0];
    
    for(int i : orig){
        if(minv > i) minv = i;
    }
    
    int sz = orig.size();
    for(int i = 0; i < sz; i++) {
        if(orig[i] != minv) {
            v.push_back(orig[i]);
        }
    }
    if(v.size() == 0) v.push_back(-1);
    return v;
}