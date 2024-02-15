#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n, m;
    string s;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cin >> n >> m;
        unordered_map<string, bool> sm(n);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> s;
            sm[s] = 1;
        }
        for (int i = 0; i < m; i++) {
            cin >> s;
            if (sm.find(s) != sm.end()) cnt++;
        }

        cout << "#" << tc << ' ' << cnt << '\n';
    }
    return 0;
}