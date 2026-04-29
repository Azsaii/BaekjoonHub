#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    int zeroCnt = 0;
    int transCnt = 0;
    int len = s.length();
    while (len != 1) {
        int cnt = 0;
        for (char& c : s) {
            if (c == '0') cnt++;
        }
        int gap = len - cnt;
        string tmp = "";
        while (gap) {
            tmp = to_string(gap % 2) + tmp;
            gap >>= 1;
        }

        s = tmp;
        zeroCnt += cnt;
        len = s.length();
        transCnt++;
    }

    vector<int> ret;
    ret.push_back(transCnt);
    ret.push_back(zeroCnt);
    return ret;
}