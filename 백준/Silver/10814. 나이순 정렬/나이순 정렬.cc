#include<bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int a, b;
    string s;
    cin >> a; 
    vector<vector<string>> v(201);
    for (int i = 0; i < a; i++) {
        cin >> b >> s;
        v[b].push_back(s);
    }
    for (int i = 1; i <= 200; i++) {
        for (string s : v[i]) {
            cout << i << ' ' << s << '\n';
        }
    }
    return 0;
}