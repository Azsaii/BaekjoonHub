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
        if (s == "push_front") { cin >> a; dq.push_front(a); }
        if (s == "push_back") { cin >> a; dq.push_back(a); }
        if (s == "pop_front") {
            if (!dq.empty()) { cout << dq.front() << '\n'; dq.pop_front(); }
            else cout << "-1\n";
        }
        if (s == "pop_back") {
            if (!dq.empty()) { cout << dq.back() << '\n'; dq.pop_back(); }
            else cout << "-1\n";
        }
        if (s == "size") cout << dq.size() << '\n';
        if (s == "empty") cout << dq.empty() << '\n';
        if (s == "front") {
            if (!dq.empty()) cout << dq.front() << '\n';
            else cout << "-1\n";
        }
        if (s == "back") {
            if (!dq.empty()) cout << dq.back() << '\n';
            else cout << "-1\n";
        }
    }
    return 0;
}