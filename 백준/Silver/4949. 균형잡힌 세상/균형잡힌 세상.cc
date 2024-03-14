#include <bits/stdc++.h>
using namespace std;
bool check(string ipt)
{
    stack<char> s;
    for (auto word : ipt)
    {
        if (word == '(' || word == '[') // 1. 여는 괄호인 경우 스택에 push
            s.push(word);
        else if (word == ')') // 2. 닫는 괄호인 경우 스택에서 pop(쌍이 맞는 경우)
        {
            if (s.empty() || s.top() != '(')
                return false;
            s.pop();
        }
        else if (word == ']')
        {
            if (s.empty() || s.top() != '[')
                return false;
            s.pop();
        }
    }

    if (s.empty()) // 3. 스택이 비지 않은 경우(-> 짝을 짓지 못한 괄호가 있음)
        return true;
    else
        return false;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    string ipt;

    while (true)
    {
        getline(cin, ipt);
        if (ipt == ".")
            break;
        bool ans = check(ipt);
        if (ans)
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }
}