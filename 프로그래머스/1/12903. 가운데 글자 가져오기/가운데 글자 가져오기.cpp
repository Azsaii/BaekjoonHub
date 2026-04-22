#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string ret = "";
    int sz = s.length();
    if (sz % 2 == 0) {
        int half = sz / 2 - 1;
        ret.append(s.substr(half, 2));
    }
    else {
        ret.push_back(s[sz / 2]);
    }
    return ret;
}