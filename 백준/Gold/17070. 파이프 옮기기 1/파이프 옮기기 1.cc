#include <iostream>
#include <vector>
#define pii pair<int, int>
using namespace std;
int n, t, res = 0;
vector<vector<bool>> v;
void dfs(pii x1, pii x2){
    auto [f, s] = x2;
    if(f == n && s == n) { res++; return; }
    if(x1.first == f) { // 가로
        if(s != n && !v[f][s + 1]) dfs(x2, {f, s + 1});
        if(f != n && s != n && !v[f + 1][s] && !v[f][s + 1] && !v[f + 1][s + 1]) dfs(x2, {f + 1, s + 1});
    }
    else if(x1.second == s) { // 세로
        if(f != n && !v[f + 1][s]) dfs(x2, {f + 1, s});
        if(f != n && s != n && !v[f + 1][s] && !v[f][s + 1] && !v[f + 1][s + 1]) dfs(x2, {f + 1, s + 1});
    }
    else {
        if(s != n && !v[f][s + 1]) dfs(x2, {f, s + 1});
        if(f != n && !v[f + 1][s]) dfs(x2, {f + 1, s});
        if(f != n && s != n && !v[f + 1][s] && !v[f][s + 1] && !v[f + 1][s + 1]) dfs(x2, {f + 1, s + 1});
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.assign(n, vector<bool>(n + 1, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            cin >> t;
            if(t == 1) v[i][j] = 1;
        }
    }
    n--;
    dfs({0, 0}, {0, 1});
    cout << res;
}