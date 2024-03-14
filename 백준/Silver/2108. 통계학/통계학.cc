#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);    
    int N, t;
    double sum = 0;
    cin >> N;
    vector<int> v(N);
    map<int, int> m;
    for (int i = 0; i < N; i++) {
        cin >> t;
        v[i] = t;
        m[t]++;
        sum += t;
    }
    sort(v.begin(), v.end());
    int j, maxv, maxi, cnt, ci = N / 2, cen = v[ci];
    j = maxv = cnt = 0;
    for (auto it : m) {
        if (maxv < it.second) {
            maxv = it.second;
            maxi = it.first;
        }
    }
    for (auto it : m) {
        if (it.second == maxv) cnt++;
        if (cnt == 2) { maxi = it.first; break; }
    }
    cout << floor(sum / N + 0.5) << '\n';
    cout << cen << '\n';
    cout << maxi << '\n';
    cout << m.rbegin()->first - m.begin()->first;
    return 0;
}