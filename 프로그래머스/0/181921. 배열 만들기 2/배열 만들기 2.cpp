#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> ret;
    int a = l;
    while(1){
        string s = to_string(a);
        int len = s.length();
        bool ch = 0;
        for(int i = 0; i < len; i++){
            int t = (s[i] - 48) % 10;
            if(t == 0 || t == 5){}
            else {
                ch = 1;
                break;
            }
        }
        if(ch == 0) break;
        a++;
    }
    while(a <= r){
        string s = to_string(a);
        int len = s.length();
        bool ch = 0;
        for(int i = 0; i < len; i++){
            int t = (s[i] - 48) % 10;
            if(t == 0 || t == 5){}
            else {
                ch = 1;
                break;
            }
        }
        if(ch == 0) ret.push_back(a);
        a += 5;
    }
    if(ret.size() == 0) ret.push_back(-1);
    return ret;
}