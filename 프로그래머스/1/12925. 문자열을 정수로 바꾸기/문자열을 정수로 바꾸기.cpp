#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int ret = 0;
    int sz = s.size() - 1;
    int cnt = 1;
    for (int i = sz; i >= 1; i--) {
        ret += (static_cast<int>(s[i]) - 48) * cnt;
        cnt *= 10;
    }
    if (s[0] == '-') ret *= -1;
    else if (s[0] != '+') ret += (static_cast<int>(s[0]) - 48) * cnt;
    return ret;
}