#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int tc, n;
    cin >> tc;
    while (tc--) {
        cin >> n;
        int v[2][100002] = {0, };
        v[0][0] = 0, v[1][0] = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= n; j++) cin >> v[i][j];
        }
        for (int i = 2; i <= n; i++) {
            v[0][i] += max(v[1][i - 2], v[1][i - 1]);
            v[1][i] += max(v[0][i - 2], v[0][i - 1]);
        }
        cout << max(v[0][n], v[1][n]) << '\n';
    }
}