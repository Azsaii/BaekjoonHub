#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int N, M, maxv = 0;
    cin >> N >> M;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        maxv = max(maxv, v[i]);
    }
    int s = 0, e = maxv, m = 0;
    long long sum = 0;
    while (s <= e) {
        sum = 0;
        m = (s + e) / 2;
        for (int i = 0; i < N; i++) {
            int val = v[i] - m;
            if (val > 0) sum += val;
        }
        if (sum >= M) s = m + 1;
        else if (sum < M) e = m - 1;
    }
    //cout << "s: " << s << ", e: " << e << ", m: " << m << '\n';
    cout << e;
}