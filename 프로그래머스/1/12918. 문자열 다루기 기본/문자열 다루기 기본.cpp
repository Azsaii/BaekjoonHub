#include <string>
#include <vector>

using namespace std;

bool solution(string s) {

    int sz = s.length();
    if(sz != 4 && sz != 6) return false;
    
    for(int i = 0; i < sz; i++){
        int a = s[i];
        if(a < 48 || a > 57) return false;
    }
    
    return true;
}