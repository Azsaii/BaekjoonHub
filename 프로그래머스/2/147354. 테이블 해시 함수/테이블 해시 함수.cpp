#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Comp {
    int col;
    Comp(int c) : col(c) {};

    bool operator() (const vector<int>& a, const vector<int>& b) {
        if (a[col] == b[col]) return a[0] > b[0];
        return a[col] < b[col];
    }
};

int solution(vector<vector<int>> data, int col, int rb, int re) {
    int ret = 0;
    rb--; re--;
    
    sort(data.begin(), data.end(), Comp(col - 1));
    for (int i = rb; i <= re; i++) {
        vector<int>& v = data[i];
        int tmp = 0;
        for (int& t : v) {
            tmp += t % (i + 1);
        }
        ret ^= tmp;
    }
    
    return ret;
}