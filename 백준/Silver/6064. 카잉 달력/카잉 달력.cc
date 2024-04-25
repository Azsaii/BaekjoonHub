#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    int n;
    while (b != 0) {
        n = a % b;
        a = b;
        b = n;
    }
    return a;
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int T, M, N, x, y;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> M >> N >> x >> y;
        int lim = lcm(M, N), res = -1;
        for (int i = x; i <= lim; i += M) {
            if ((i - y) % N == 0) { res = i; break; }
        }
        cout << res << '\n';
    }
}