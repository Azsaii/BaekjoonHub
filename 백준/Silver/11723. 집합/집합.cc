#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int M, a = 0, b;
    cin >> M;
    string s;
    for (int i = 0; i < M; i++) {
        cin >> s;
        if (s[1] != 'l' && s[1] != 'm') cin >> b;
        b--;
        switch (s[1]) {
        case 'd': a = a | (1 << b); break;
        case 'e': a = a & ~(1 << b); break;
        case 'h': (a & (1 << b)) ? cout << "1\n" : cout << "0\n"; break;
        case 'o': a = a ^ (1 << b); break;
        case 'l': a = (1 << 20) - 1; break;
        case 'm': a = 0; break;
        }
    }
    return 0;
}