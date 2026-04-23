#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> v) {
    vector<int> r1(3, -1);
    int sz = v.size();
    int cnt = 0;
    int tmp = 1;
    int maxv = -1;

    for (int i = 0; i < sz; i++) {
        if (v[i] == tmp) cnt++;
        if (++tmp == 6) tmp = 1;
    }
    r1[0] = cnt;
    if (maxv < cnt) maxv = cnt;

    cnt = 0;
    tmp = 1;
    for (int i = 0; i < sz; i++) {

        if (i % 2 == 0 && v[i] == 2) cnt++;

        else if (i % 2 != 0) {
            if (v[i] == tmp) cnt++;

            tmp++;
            if (tmp == 2) tmp++;
            else if (tmp == 6) tmp = 1;
        }

    }
    r1[1] = cnt;
    if (maxv < cnt) maxv = cnt;

    cnt = 0;
    tmp = 0;
    vector<int> vt = { 3, 1, 2, 4, 5 };
    for (int i = 0; i < sz; i++) {

        if (v[i] == vt[tmp]) cnt++;
        if (i != 0 && i % 2 == 1) tmp++;
        if (tmp == 5) tmp = 0;
    }
    r1[2] = cnt;
    if (maxv < cnt) maxv = cnt;

    vector<int> ret;
    for (int i = 0; i < 3; i++) {
        if (maxv == r1[i]) ret.push_back(i + 1);
    }
    return ret;
}