#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int M, a;
    cin >> M;
    vector<bool> v(21, 0);
    string s;
    for (int i = 0; i < M; i++) {
        cin >> s;
        if (s[1] != 'l' && s[1] != 'm') cin >> a;
        switch (s[1]) {
        case 'd': v[a] = 1; break;
        case 'e': v[a] = 0; break;
        case 'h': cout << v[a] << '\n'; break;
        case 'o': v[a] ? v[a] = 0 : v[a] = 1; break;
        case 'l': v.assign(21, 1); break;
        case 'm': v.assign(21, 0); break;
        }
    }
    return 0;
}