#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int T, x, y;
    cin >> T;
    vector<int> v(T, 1);
    vector<pii> vp(T);
    for (int i = 0; i < T; i++) {
        cin >> x >> y;
        vp[i] = { x, y };
    }
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < T; j++) {
            if (i == j) continue;
            if (vp[i].first < vp[j].first && vp[i].second < vp[j].second) v[i]++;
        }
    }
    for (int i = 0; i < T; i++) cout << v[i] << ' ';
    return 0;
}