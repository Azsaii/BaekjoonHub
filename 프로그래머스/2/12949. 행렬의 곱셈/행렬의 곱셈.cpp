#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> v1, vector<vector<int>> v2) {
    vector<vector<int>> ret;
    int row1 = v1.size();
    int mid = v1[0].size();
    int col2 = v2[0].size();

    for (int i = 0; i < row1; i++) {
        vector<int> tmp;
        for (int k = 0; k < col2; k++) {
            int sum = 0;
            for (int j = 0; j < mid; j++) {
                sum += v1[i][j] * v2[j][k];
            }
            tmp.push_back(sum);
        }
        ret.push_back(tmp);
    }
    return ret;
}