#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    int sz = s.length();

    for (int i = 0; i < sz; i++) {
        if (s[i] != ' ') {
            if ((s[i] >= 65 && s[i] <= 90 && s[i] + n > 90)
                || (s[i] >= 97 && s[i] <= 122 && s[i] + n > 122)) {
                s[i] = s[i] + n - 26;
            }
            else s[i] += n;
        }
    }
    
    return s;
}