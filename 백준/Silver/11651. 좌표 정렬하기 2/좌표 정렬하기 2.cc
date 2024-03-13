#include<bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int t, a, b;
    cin >> t;
    vector<pair<int, int>> v(t);
    for (int i = 0; i < t; i++) {
        cin >> a >> b;
        v[i] = { b, a };
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < t; i++) cout << v[i].second << ' ' << v[i].first << '\n';
    return 0;
}