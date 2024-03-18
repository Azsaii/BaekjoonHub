#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n, m, t, a, b;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (i == 0) v[i] = t;
        else v[i] = v[i - 1] + t;
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (a >= 2) cout << v[b - 1] - v[a - 2] << '\n';
        else cout << v[b - 1] << '\n';
    }
    return 0;
}