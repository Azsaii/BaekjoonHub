#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> ret;
    for(const auto& v : queries){
        int sz = ret.size();
        int minv = -1;
        for(int i = v[0]; i <= v[1]; i++){
            if(arr[i] > v[2]){
                if(minv == -1) minv = arr[i];
                else if(arr[i] < minv) minv = arr[i];
            }
        }
        if(minv == -1) ret.push_back(-1);
        else ret.push_back(minv);
    }
    return ret;
}