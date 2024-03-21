#include <bits/stdc++.h>
using namespace std;
int res, t;
void dfs(int x) {
    if (x > t) return;
    if (x == t) { res++; return; }
    for (int i = 1; i <= 3; i++) dfs(x + i);
}
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> t;
        res = 0;
        for (int i = 1; i <= 3; i++) dfs(i);
        cout << res << '\n';
    }
    return 0;
}