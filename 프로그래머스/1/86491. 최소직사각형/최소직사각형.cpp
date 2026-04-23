#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> v) {
    int row = v.size();
    int w = v[0][0];
    int h = v[0][1];

    for (int i = 1; i < row; i++) {
        int t1w = w > v[i][0] ? w : v[i][0];
        int t1h = h > v[i][1] ? h : v[i][1];
        int val1 = t1w * t1h;

        int t2w = w > v[i][1] ? w : v[i][1];
        int t2h = h > v[i][0] ? h : v[i][0];
        int val2 = t2w * t2h;

        if (val1 < val2) {
            w = t1w;
            h = t1h;
        }
        else {
            w = t2w;
            h = t2h;
        }
    }

    return w * h;
}