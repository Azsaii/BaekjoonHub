#include <string>
#include <stack>

using namespace std;

int solution(string s) {
    int ret = 0;
    int len = s.length();
    for (int i = 0; i < len; i++) {
        stack<char> st;
        bool ch = true;
        for (int k = 0; k < len; k++) {
            if (s[k] == '(' || s[k] == '{' || s[k] == '[') st.push(s[k]);
            else if (st.size() != 0) {
                char& top = st.top();
                if ((top == '(' && s[k] == ')') 
                    || (top == '{' && s[k] == '}') 
                    || (top == '[' && s[k] == ']')) st.pop();
                else {
                    ch = false;
                    break;
                }
            }
            else {
                ch = false;
                break;
            }
        }
        if (ch == true && st.size() == 0) ret++;

        string tmp = s.substr(1, len - 1);
        tmp += s[0];
        s = tmp;
    }
    return ret;
}