#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numLog) {
    string ret;
    int sz = numLog.size();
    for(int i = 1; i < sz; i++){
        int gap = numLog[i] - numLog[i - 1];
        if(gap == 1) ret += 'w';
        else if(gap == -1) ret += 's';
        else if(gap == 10) ret += 'd';
        else if(gap == -10) ret += 'a';
    }
    return ret;
}