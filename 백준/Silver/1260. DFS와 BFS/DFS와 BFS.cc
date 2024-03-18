#include <bits/stdc++.h>
using namespace std;
vector<bool> vst;
vector<vector<int>> edges;
queue<int> q;
void dfs(int x) {
    vst[x] = 1;
    cout << x << ' ';
    for (int i : edges[x]) {
        if (!vst[i]) dfs(i);
    }
}
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n, m, v, a, b;
    cin >> n >> m >> v;
    edges.resize(n + 1);
    vst.assign(n + 1, 0);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) sort(edges[i].begin(), edges[i].end());
    dfs(v);
    cout << '\n';
    vst.assign(n + 1, 0);
    q.push(v);
    vst[v] = 1;
    while (!q.empty()) {
        int top = q.front();
        cout << top << ' ';
        q.pop();
        for (int i : edges[top]) {
            if (vst[i]) continue;
            vst[i] = 1;
            q.push(i);
        }
    }
    return 0;
}