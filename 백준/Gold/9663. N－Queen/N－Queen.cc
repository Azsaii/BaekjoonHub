#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
int n, res = 0;
void dfs(pii p, int cnt, vector<pii> v) {
    if (cnt == n) { res++; return; }
    auto [y, x] = p;
    for (int i = 0; i < n; i++) { // 현재 후보 열.
        if (v[i].first != -1) continue; // i번째 열에 이미 퀸이 있음
        bool ch = 0;
        for (int j = 0; j < n; j++) {
            if (v[j].first == -1) continue; // 퀸이 아직 없으므로 패스
            if (abs(v[j].first - (y + 1)) == abs(v[j].second - i)) { // 접근 불가 
                ch = 1; break; 
            }   
        }
        if (!ch) {
            v[i] = { y + 1, i }; // 방문처리
            dfs({ y + 1, i }, cnt + 1, v);
            v[i] = { -1, -1 };
        }
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<pii> v(14, {-1, -1});
        v[i] = {0, i};
        dfs({ 0, i }, 1, v);
    }
    cout << res;
}