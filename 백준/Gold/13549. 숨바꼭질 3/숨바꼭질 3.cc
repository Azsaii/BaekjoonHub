#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n, k;
    bool mode = 0;
    cin >> n >> k;
    if (n > k) { swap(n, k); mode = 1; }
    vector<int> v(200001, k - n);
    priority_queue<pii, vector<pii>, greater<pii>> q;
    v[n] = 0;
    q.push({ v[n], n });
    while (!q.empty()) {
        auto [f, s] = q.top();
        q.pop();
        if (f > v[s]) continue;
        if (s + 1 <= k && v[s + 1] > f + 1) {
            v[s + 1] = f + 1;
            q.push({ f + 1, s + 1 });
        }
        if (abs(k - s * 2) <= k - s && v[s * 2] > f && mode == 0) {
            v[s * 2] = f;
            q.push({ f, s * 2 });
        }
        if (s - 1 >= 0 && v[s - 1] > f + 1) {
            v[s - 1] = f + 1;
            q.push({ f + 1, s - 1 });
        }
    }
    cout << v[k];
}