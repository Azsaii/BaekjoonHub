#include <bits/stdc++.h>
using namespace std;
int n;
int v[1000];
vector<int> tmp;
int find(int s, int e, int x) {
    while (s < e) {
        int m = (s + e) / 2;
        if (tmp[m] < x) s = m + 1;
        else e = m;
    }
    return e;
}
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i];
    int r[1000] = {1, }, l[1000] = {1, }, cnt = 0, maxv = 0;
    tmp.push_back(v[0]); r[0] = 1;
    for (int i = 1; i < n; i++) {
        if (tmp[cnt] < v[i]) { 
            tmp.push_back(v[i]); 
            cnt++;
            r[i] = cnt + 1;
        }
        else {
            int p = find(0, tmp.size() - 1, v[i]);
            tmp[p] = v[i];
            r[i] = p + 1;
        }
    }
    tmp.clear(); tmp.push_back(v[n - 1]); l[n - 1] = 1; cnt = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (tmp[cnt] < v[i]) {
            tmp.push_back(v[i]);
            cnt++;
            l[i] = cnt + 1;
        }
        else {
            int p = find(0, tmp.size() - 1, v[i]);
            tmp[p] = v[i];
            l[i] = p + 1;
        }
    }
    for (int i = 0; i < n; i++)  maxv = max(maxv, r[i] + l[i]);
    cout << maxv - 1;
}