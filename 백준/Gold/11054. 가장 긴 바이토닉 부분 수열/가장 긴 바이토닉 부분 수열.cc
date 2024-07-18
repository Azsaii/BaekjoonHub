#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    vector<int> tmp;
    int v[1000], r[1000], l[1000], n, maxv = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i];
    tmp.push_back(v[0]); r[0] = 1;
    for (int i = 1; i < n; i++) {
        if (tmp.back() < v[i]) {
            tmp.push_back(v[i]); 
            r[i] = tmp.size();
        }
        else {
            auto it = lower_bound(tmp.begin(), tmp.end(), v[i]);
            *it = v[i];
            r[i] = distance(tmp.begin(), it) + 1;
        }
    }
    tmp.clear(); tmp.push_back(v[n - 1]); l[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (tmp.back() < v[i]) {
            tmp.push_back(v[i]);
            l[i] = tmp.size();
        }
        else {
            auto it = lower_bound(tmp.begin(), tmp.end(), v[i]);
            *it = v[i];
            l[i] = distance(tmp.begin(), it) + 1;
        }
    }
    for (int i = 0; i < n; i++)  maxv = max(maxv, r[i] + l[i]);
    cout << maxv - 1;
}