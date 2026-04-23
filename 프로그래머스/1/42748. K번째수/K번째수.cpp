#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> com) {
    vector<int> ret;
    int sz = com.size();
    for(int i = 0; i < sz; i++){
        int a = com[i][0] - 1;
        int b = com[i][1] - 1;
        int c = com[i][2] - 1;
        vector<int> v;
        for(int k = a; k <= b; k++){
            v.push_back(arr[k]);
        }
        sort(v.begin(), v.end());
        ret.push_back(v[c]);
        
    }
    return ret;
}