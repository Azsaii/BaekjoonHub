#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> v1, vector<vector<int>> v2) {
    vector<vector<int>> ret;
    int row = v1.size();
    int col = v1[0].size();
    ret.resize(row);
    
    for(int i = 0; i < row; i++){
        for(int k = 0; k < col; k++){
            ret[i].push_back(v1[i][k] + v2[i][k]);
        }
    }
    return ret;
}