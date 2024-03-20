#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int N, M, a, b, res = 0;
    cin >> N >> M;
    vector<vector<int>> v(N + 1);
    vector<bool> vst(N + 1, 0);
    for (int i = 0; i < M; i++) { 
        cin >> a >> b; 
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<int> q;
    q.push(1); vst[1] = 1;
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        for (int i : v[f]) {
            if (vst[i])continue;
            vst[i] = 1;
            q.push(i);
            res++;
        }
    }
    cout << res;
    return 0;
}