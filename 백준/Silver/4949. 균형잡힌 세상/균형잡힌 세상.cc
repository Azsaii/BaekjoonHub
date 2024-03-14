#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);    
    while (1) {
        string str;
        getline(cin, str);
        if (str[0] == '.') break;
        stack<char> s;
        bool ch = 0; 
        for (int i = 0; i < str.size(); i++) {
            char c = str[i];
            if (ch) continue;
            if (c == '(' || c == '[') s.push(c);
            else if (c == ')' || c == ']') {
                if (!s.empty() && ((s.top() == '(' && c == ')') || (s.top() == '[' && c == ']'))) s.pop();
                else ch = 1;
            }
        }
        if (!ch && s.empty()) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}