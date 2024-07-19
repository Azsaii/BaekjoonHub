#include <bits/stdc++.h>
using namespace std;
int n, m, maxv = 0;
int v[21][21];
bool vst[26] = { 0, };
void dfs(pair<int, int> x, int sum) {
    auto [cr, cc] = x;
    vst[v[cr][cc]] = true;
    if (cr < n - 1 && !vst[v[cr + 1][cc]]) {
        vst[v[cr + 1][cc]] = 1; dfs({ cr + 1, cc }, sum + 1); vst[v[cr + 1][cc]] = 0;
    }
    if (cr > 0 && !vst[v[cr - 1][cc]]) {
        vst[v[cr - 1][cc]] = 1; dfs({ cr - 1, cc }, sum + 1); vst[v[cr - 1][cc]] = 0;
    }
    if (cc < m - 1 && !vst[v[cr][cc + 1]]) {
        vst[v[cr][cc + 1]] = 1; dfs({ cr, cc + 1 }, sum + 1); vst[v[cr][cc + 1]] = 0;
    }
    if (cc > 0 && !vst[v[cr][cc - 1]]) {
        vst[v[cr][cc - 1]] = 1; dfs({ cr, cc - 1 }, sum + 1); vst[v[cr][cc - 1]] = 0;
    }
    vst[v[cr][cc]] = false;
    maxv = max(maxv, sum);
}
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> m;
    char c;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) { cin >> c; v[i][j] = c - 'A'; }
    dfs({ 0, 0 }, 1);
    cout << maxv;
}