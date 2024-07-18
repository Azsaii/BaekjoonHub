#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n; cin >> n;
    bool m[33][33];
    long long dp[33][33][3] = {0, };
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> m[i][j];
    dp[1][2][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 3; j <= n; j++) {
            if (m[i][j]) continue;
            dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][1];
            dp[i][j][2] = dp[i - 1][j][2] + dp[i - 1][j][1];
            if (m[i - 1][j] || m[i][j - 1]) continue;
            dp[i][j][1] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
        }
    }
    cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
}