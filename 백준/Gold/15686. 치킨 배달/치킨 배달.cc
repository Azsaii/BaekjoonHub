#include <iostream>
#include <vector>
#define pii pair<int, int>
using namespace std;
int n, m, t, hs = 0, cs = 0, res = INT32_MAX;
pii home[100], ch[13];
int dst[13][100], vst[13];
void calc(){
    int d = 0;
    for(int i = 0; i < hs; i++) {
        int minv = INT32_MAX;
        for(int j = 0; j < m; j++) {
            minv = min(minv, dst[vst[j]][i]);
        }
        d += minv;
    }
    res = min(res, d);
}
void dfs(int x, int cnt){
    if(cnt == m) calc();
    for(int i = x; i < cs; i++) {
        vst[cnt] = i;
        dfs(i + 1, cnt + 1);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> t;
            if(t == 1) home[hs++] = {i, j};
            else if(t == 2) ch[cs++] = {i, j};
        }
    }
    for(int i = 0; i < cs; i++) {
        auto [cr, cc] = ch[i];
        for(int j = 0; j < hs; j++) {
            auto [hr, hc] = home[j];
            dst[i][j] = abs(cr - hr) + abs(cc - hc);
        }
    }
    dfs(0, 0);
    cout << res;
}