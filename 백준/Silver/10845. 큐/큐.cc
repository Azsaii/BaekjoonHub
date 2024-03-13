#include<bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int t, a;
    string s;
    cin >> t;
    queue<int> q;
    for (int i = 0; i < t; i++) {
        cin >> s;
        if (s[1] == 'u') { cin >> a; q.push(a); }
        if (s[1] == 'o') {
            if (!q.empty()) { cout << q.front() << '\n'; q.pop(); }
            else cout << "-1\n";
        }
        if (s[0] == 's') cout << q.size() << '\n';
        if (s[0] == 'e') cout << q.empty() << '\n';
        if (s[0] == 'f') {
            if (!q.empty()) cout << q.front() << '\n';
            else cout << "-1\n";
        }
        if (s[0] == 'b') {
            if (!q.empty()) cout << q.back() << '\n';
            else cout << "-1\n";
        }
    }
    return 0;
}