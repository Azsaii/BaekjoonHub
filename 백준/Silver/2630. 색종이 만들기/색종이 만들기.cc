#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int N, t, a = 0, b = 0, e = 4;
    cin >> N;
    vector<vector<int>> v(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> t;
            v[i][j] = t;
            if (t == 0) a++;
            else b++;
        }
    }
    while (N != 1) {
        int c = 0, d = 0;
        for (int i = 0; i < N; i += 2) {
            for (int j = 0; j < N; j += 2) {
                int sum = v[i][j] + v[i + 1][j] + v[i][j + 1] + v[i + 1][j + 1];
                if (sum == 0) a -= 3;
                else if (sum == e)  b -= 3;
                v[c][d++] = sum;
                if (d == N / 2) { c++; d = 0; }
            }
        }
        N /= 2; e *= 4;
    }
    cout << a << '\n' << b;
    return 0;
}