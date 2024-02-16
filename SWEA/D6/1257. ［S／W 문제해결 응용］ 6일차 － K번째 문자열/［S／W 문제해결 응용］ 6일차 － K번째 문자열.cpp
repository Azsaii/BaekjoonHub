#include<bits/stdc++.h>
using namespace std;
int main() {
    int T, k;
    string s;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> k >> s;
        set<string> ss;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            for (int j = len - i; j >= 0; j--) {
                if (i == 0 && j == 0) continue;
                ss.insert(s.substr(i, j));
            }
        }
        size_t sz = ss.size();
        sz--;
        cout << "#" << tc << ' ';
        if (sz < k) {
            cout << "none\n";
            continue;
        }
        set<string>::iterator it = ss.begin();
        advance(it, k);
        cout << *it << '\n';
    }
    return 0;
}