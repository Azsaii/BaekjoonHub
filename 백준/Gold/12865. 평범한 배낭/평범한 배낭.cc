#include <bits/stdc++.h>
using namespace std;
int n, k, dp[101][100001], w[101], v[101];
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)  cin >> w[i] >> v[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j >= w[i]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            else dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][k];
}