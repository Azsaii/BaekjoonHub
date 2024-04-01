#include <bits/stdc++.h>
using namespace std;
vector<bool> temp;
vector<vector<int>> v, res;
void dfs(int x) {
    if (temp[x]) return;
    temp[x] = 1;
    for (int i : v[x]) dfs(i);
}
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int N, t;
    cin >> N;
    v.resize(N);
    res.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> t;
            if (t == 1) v[i].push_back(j);
        }
    }
    for (int i = 0; i < N; i++) {
        if (v[i].size() == 0) continue;
        for (int j : v[i]) {
            temp.assign(N, 0);
            dfs(j);
            for (int k = 0; k < N; k++) {
                if (temp[k]) res[i][k] = 1;
            }
        }  
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
}