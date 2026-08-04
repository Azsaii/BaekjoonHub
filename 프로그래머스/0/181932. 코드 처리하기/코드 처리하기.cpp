#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    string ret = "";
    bool mode = 0;
    int sz = code.length();
    for(int i = 0; i < sz; i++){
        if(!mode && code[i] != '1' && i % 2 == 0) ret += code[i];
        else if(mode && code[i] != '1' && i % 2 == 1) ret += code[i];
        if(code[i] == '1') mode = !mode;
    }
    if(ret.length() == 0) return "EMPTY";
    return ret;
}