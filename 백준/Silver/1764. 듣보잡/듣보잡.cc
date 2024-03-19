#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    unordered_map<string, bool> m;
    vector<string> v;
    string s;
    for (int i = 0; i < N + M; i++) {
        cin >> s;
        if (i < N) m[s] = 1;
        else if (m[s]) v.push_back(s);
    }
    cout << v.size() << '\n';
    sort(v.begin(), v.end());
    for (string str : v) cout << str << '\n';
    return 0;
}