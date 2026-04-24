#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> l, vector<int> v) {
    vector<int> ret;
    int cnt = 0;
    int z = 0;
    for (int i = 0; i < 6; i++) {
        if (l[i] == 0) {
            z++;
        }
        else {
            for (int k = 0; k < 6; k++) {
                if (l[i] == v[k]) {
                    cnt++;
                    break;
                }
            }
        }
    }

    int minv = cnt;
    int maxv = cnt + z;

    if (minv <= 1) minv = 6;
    else minv = 7 - minv;

    if (maxv <= 1) maxv = 6;
    else maxv = 7 - maxv;

    ret.push_back(maxv);
    ret.push_back(minv);
    return ret;
}