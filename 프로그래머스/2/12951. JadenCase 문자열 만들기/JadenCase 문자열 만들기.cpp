#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    bool ch = false;
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] == ' ') {
            ch = true;
        }
        else {
            if (ch == true) {
                if (s[i] >= 97 && s[i] <= 122) {
                    s[i] -= 32;
                }
                ch = false;
            }
            else if (s[i] >= 65 && s[i] <= 90) {
                s[i] += 32;
            }
        } 
    }

    if (s[0] >= 97 && s[0] <= 122) {
        s[0] -= 32;
    }
    return s;
}