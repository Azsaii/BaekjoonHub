#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> key, vector<string> g) {
    vector<int> ret;
    vector<int> alp(26, 101);
    for (string& s : key) {
        int len = s.length();
        for (int i = 0; i < len; i++) {
            int index = s[i] - 65;
            if (alp[index] > i) alp[index] = i;
        }
    }

    for (string& s : g) {
        int cnt = 0;
        bool ch = true;
        for (char& c : s) {
            int val = alp[c - 65];
            if (val == 101) {
                ret.push_back(-1);
                ch = false;
                break;
            }
            else cnt += val + 1;
        }
        if(ch == true) ret.push_back(cnt);
    }
    return ret;
}