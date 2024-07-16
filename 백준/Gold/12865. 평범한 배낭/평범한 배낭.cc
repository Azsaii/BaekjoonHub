#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n, k, w, val;
    cin >> n >> k;
    vector<pii> v(n + 1);
    vector<vector<int>> dp(n + 1, vector(k + 1, 0));
    for (int i = 1; i <= n; i++) {
        cin >> w >> val;
        v[i] = { w, val };
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j >= v[i].first) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i].first] + v[i].second);
            else dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][k];
}