#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> v) {
    string ret = "";
    int sz = v.size();
    for (int i = 1; i < sz; i++) {
        if (v[i] % 2 != 0) v[i]--;
        if (v[i] == 1) v[i] = 0;

        int cnt = v[i] / 2;
        while (cnt--) ret += i + 48;
    }

    string rev = ret;
    reverse(rev.begin(), rev.end());

    ret += '0';
    ret += rev;
    return ret;
}