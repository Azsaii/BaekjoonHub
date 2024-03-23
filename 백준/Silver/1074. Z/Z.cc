#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int N, r, c, cur = 0;
    cin >> N >> r >> c;
    int sz = pow(2, N);
    int pw = pow(4, N - 1);
    int mod = sz / 2;
    while (1) {
        int h = sz / 2, p;
        if (r < h && c < h) p = 0;
        if (r < h && c >= h) p = 1;
        if (r >= h && c < h) p = 2;
        if (r >= h && c >= h) p = 3;
        cur += pw * p;
        r %= mod; c %= mod;
        pw /= 4; sz /= 2; mod /= 2;
        if (sz == 1) break;
    }
    cout << cur;
    return 0;
}