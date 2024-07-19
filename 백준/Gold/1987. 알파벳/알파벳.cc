#include <bits/stdc++.h>
#define MAX 21
using namespace std;
int n, m, maxv = 0;
int v[MAX][MAX], dp[MAX][MAX];
void dfs(pair<int, int> x, int sum, int his) {
    auto [cr, cc] = x;
    his |= (1 << v[cr][cc]);
    if (dp[cr][cc] == his) return;
    dp[cr][cc] = his;
    if (cr < n - 1 && !(his & (1 << v[cr + 1][cc]))) dfs({ cr + 1, cc }, sum + 1, his);
    if (cr > 0 && !(his & (1 << v[cr - 1][cc]))) dfs({ cr - 1, cc }, sum + 1, his);
    if (cc < m - 1 && !(his & (1 << v[cr][cc + 1]))) dfs({ cr, cc + 1 }, sum + 1, his);
    if (cc > 0 && !(his & (1 << v[cr][cc - 1]))) dfs({ cr, cc - 1 }, sum + 1, his);
    maxv = max(maxv, sum);
}
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> m;
    char c;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) { cin >> c; v[i][j] = c - 'A'; }
    dfs({ 0, 0 }, 1, 0);
    cout << maxv;
}