#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string ret = "";
    int cnt = 0;
    while(1){
        if (cnt % 2 == 0) ret.append("수");
        else ret.append("박");
        cnt++;
        if(cnt == n) break;
    }
    return ret;
}