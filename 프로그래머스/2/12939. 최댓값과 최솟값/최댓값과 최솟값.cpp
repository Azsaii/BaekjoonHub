#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int maxv = 0;
    int minv = 0;
    int len = s.length();
    int tmp = 0;
    int e = 1;
    int i = len - 1;
    while (s[i] != ' ') {
        if (s[i] == '-') {
            tmp *= -1;
        }
        else {
            tmp += (s[i] - 48) * e;
            e *= 10;
        }
        i--;
    }

    maxv = tmp;
    minv = tmp;
    tmp = 0;
    e = 1;
    i--;
    for (; i >= 0; i--) {
        if (s[i] == ' ') {
            if (maxv < tmp) maxv = tmp;
            if (minv > tmp) minv = tmp;
            e = 1;

            tmp = 0;
        }
        else if (s[i] == '-') {
            tmp *= -1;
        }
        else {
            tmp += (s[i] - 48) * e;
            e *= 10;
        }
    }
    
    if (maxv < tmp) maxv = tmp;
    if (minv > tmp) minv = tmp;

    string ret = "";
    ret += to_string(minv);
    ret += ' ';
    ret += to_string(maxv);
    return ret;
}