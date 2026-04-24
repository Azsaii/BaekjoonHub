#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> w) {
    vector<int> ret;
    int col = w[0].length();
    int row = w.size();
    int lx = 51;
    int ly = 51;
    int rx = 0;
    int ry = 0;
    for (int i = 0; i < row; i++) {
        for (int k = 0; k < col; k++) {
            if (w[i][k] == '#') {
                if (lx > i) lx = i;
                if (ly > k) ly = k;
            }
        }
    }
    for (int i = row - 1; i >= 0; i--) {
        for (int k = col - 1; k >= 0; k--) {
            if (w[i][k] == '#') {
                if (rx < i) rx = i;
                if (ry < k) ry = k;
            }
        }
    }

    ret.push_back(lx);
    ret.push_back(ly);
    ret.push_back(rx + 1);
    ret.push_back(ry + 1);
    
    return ret;
}