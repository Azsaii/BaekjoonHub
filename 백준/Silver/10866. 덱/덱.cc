#include<bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int t, a;
    string s;
    cin >> t;
    deque<int> dq;
    for (int i = 0; i < t; i++) {
        cin >> s;
        if (s[1] == 'u' && s[5] == 'f') { cin >> a; dq.push_front(a); }
        if (s[1] == 'u' && s[5] == 'b') { cin >> a; dq.push_back(a); }
        if (s[1] == 'o' && s[4] == 'f') {
            if (!dq.empty()) { cout << dq.front() << '\n'; dq.pop_front(); }
            else cout << "-1\n";
        }
        if (s[1] == 'o' && s[4] == 'b') {
            if (!dq.empty()) { cout << dq.back() << '\n'; dq.pop_back(); }
            else cout << "-1\n";
        }
        if (s[0] == 's') cout << dq.size() << '\n';
        if (s[0] == 'e') cout << dq.empty() << '\n';
        if (s[0] == 'f') {
            if (!dq.empty()) cout << dq.front() << '\n';
            else cout << "-1\n";
        }
        if (s[0] == 'b') {
            if (!dq.empty()) cout << dq.back() << '\n';
            else cout << "-1\n";
        }
    }
    return 0;
}