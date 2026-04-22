#include <string>
#include <vector>

using namespace std;

string solution(vector<string> v) {
    string ret = "";

    int sz = v.size();
    int i = 0;
    for (; i < sz; i++) {
         if (v[i] == "Kim") break;
     }
     ret.append("김서방은 ").append(to_string(i)).append("에 있다");
    
    return ret;
}