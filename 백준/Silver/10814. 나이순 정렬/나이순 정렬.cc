#include<bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int a, b;
    string s;
    cin >> a; 
    vector<vector<string>> v(201);
    map<int, bool> m;
    for (int i = 0; i < a; i++) {
        cin >> b >> s;
        v[b].push_back(s);
        m[b] = 1;
    }
    for (auto it : m) {
        int c = it.first;
        for (string str : v[c]) {
            cout << c << ' ' << str << '\n';
        }
    }
    return 0;
}