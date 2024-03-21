#include <bits/stdc++.h>
using namespace std;
int N, sum = 0;
vector<vector<int>> v;
vector<int> vst;
void dfs(int x) {
    vst[x] = 1;
    for (int i : v[x]) if (!vst[i]) dfs(i);
}
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int M, a, b, res = 0;
    cin >> N >> M;
    v.resize(N + 1); vst.assign(N + 1, 0);
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= N; i++) {
        if (!vst[i]) { dfs(i); res++; }        
    }
    cout << res;
    return 0;
}