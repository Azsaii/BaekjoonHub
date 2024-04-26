#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int N, M;
    string s, str;
    cin >> N >> M >> s;
    int tarlen = 2 * N + 1, res = 0;
    for (int i = 0; i < tarlen; i++) {
        if (i % 2 == 0) str.append("I");
        else str.append("O");
    }
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'I') {
            if (s.substr(i, tarlen) == str) res++;  
        }
    }
    cout << res << '\n';
}