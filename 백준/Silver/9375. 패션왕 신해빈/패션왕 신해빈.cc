#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int T, N;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> N;
        cin.ignore();
        string str;
        int mul = 1;
        unordered_map<string, int> m;
        vector<int> v;
        for (int i = 0; i < N; i++) {
            getline(cin, str);
            size_t pos = str.find(' ');
            str = str.substr(pos + 1);
            m[str] += 1;
        }
        for (auto [key, val] : m) v.push_back(val);
        for (int i = 0; i < v.size(); i++) mul *= (v[i] + 1);
        cout << mul - 1<< '\n';
    }
}