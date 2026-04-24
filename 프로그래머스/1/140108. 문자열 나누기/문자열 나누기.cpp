#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int ret = 1;
    char first = s[0];
    int fcnt = 1;
    int ocnt = 0;
    int len = s.length();
    for (int i = 1; i < len; i++) {
        if (s[i] == first) fcnt++;
        else ocnt++;

        if (fcnt == ocnt) {
            first = s[i + 1];
            fcnt = 1;
            ocnt = 0;
            i++;
            if(first != '\0') ret++;
        }
    }
    return ret;
}