#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<int> v(N);
    vector<vector<int>> res(N, vector<int>(2));
    for (int i = 0; i < N; i++) cin >> v[i];
    if (N < 3) {
        int sum = 0;
        for (int i = 0; i < N; i++) sum += v[i];
        cout << sum; return 0;
    }
    res[0][0] = v[0];
    res[1][0] = v[1];
    res[1][1] = v[1] + v[0];
    res[2][0] = v[2] + v[0];
    res[2][1] = v[2] + v[1];
    for (int i = 3; i < N; i++) {
        res[i][0] = v[i] + (res[i - 2][0] > res[i - 2][1] ? res[i - 2][0] : res[i - 2][1]);
        res[i][1] = v[i] + res[i - 1][0];
    }
    cout << (res[N - 1][0] > res[N - 1][1] ? res[N - 1][0] : res[N - 1][1]);
    return 0;
}