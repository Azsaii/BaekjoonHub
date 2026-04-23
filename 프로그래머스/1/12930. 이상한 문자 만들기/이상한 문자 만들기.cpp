#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string ret = "";
    int sz = s.length();
    int k = 0;
    for (int i = 0; i < sz; i++) {
        if (s[i] != ' ') {
            if (k % 2 == 0) ret += toupper(s[i]);
            else ret += tolower(s[i]);
            k++;
        }
        else {
            ret += ' ';
            k = 0;
        }
    }
    
    return ret;
}