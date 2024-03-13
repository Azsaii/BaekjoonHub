#include<bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int a, b;
    string s;
    cin >> a;
    vector<pair<pair<int, int>, string>> v(a);
    for (int i = 0; i < a; i++) {
        cin >> b >> s;
        v[i] = { {b,i}, s };
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < a; i++) cout << v[i].first.first << ' ' << v[i].second << '\n';
    return 0;
}