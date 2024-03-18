#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n, t;
    cin >> n;
    vector<pii> v(n);
    vector<int> r(n);
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; i++) { cin >> t; v[i] = { t, i }; cnt[t]++; }
    sort(v.begin(), v.end());
    int index = 0;
    for (int i = 0; i < n; i++) {
        auto [f, s] = v[i];
        r[s] = index;
        if (cnt[f] == 1) index++;
        else cnt[f]--;
    }
    for (int i = 0; i < n; i++) cout << r[i] << ' ';
    return 0;
}