#include <iostream>
#include <vector>
#define pii pair<int, int>
using namespace std;
int n, m, t, res = INT32_MAX;
vector<pii> home, ch;
vector<bool> vst;
void calc(){
    int dst = 0;
    for(int i = 0; i < home.size(); i++) {
        auto [hr, hc] = home[i];
        int minv = INT32_MAX;
        for(int j = 0; j < ch.size(); j++) {
            if(!vst[j]) continue;
            auto [cr, cc] = ch[j];
            minv = min(minv, abs(hr - cr) + abs(hc - cc));
        }
        dst += minv;
    }
    res = min(res, dst);
}
void dfs(int x, int cnt){
    if(cnt == m) calc();
    for(int i = x; i < ch.size(); i++) {
        if(vst[i]) continue;
        vst[i] = 1;
        dfs(i, cnt + 1);
        vst[i] = 0;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> t;
            if(t == 1) home.push_back({i, j});
            else if(t == 2) ch.push_back({i, j});
        }
    }
    vst.resize(ch.size());
    dfs(0, 0);
    cout << res;
}