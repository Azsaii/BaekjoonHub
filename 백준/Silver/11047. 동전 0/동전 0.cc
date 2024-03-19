#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int N, K, res = 0;
    cin >> N >> K;
    vector<int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < N; i++) {
        int a = K / v[i];
        if (a != 0) {
            res += a;
            K -= a * v[i];
        }
    }
    cout << res;
    return 0;
}