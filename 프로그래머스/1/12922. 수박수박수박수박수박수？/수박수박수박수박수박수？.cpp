#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string ret = "";
    int cnt = n / 2;
    while (cnt != 0) {
        ret.append("수박");
        cnt--;
    }
    if(n % 2 == 1) ret.append("수");
    return ret;
}
