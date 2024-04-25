#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int T, N;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> N;
        vector<ll> v = { 1, 1, 1, 2, 2 };
        if (N <= 5) { cout << v[N - 1] << '\n'; continue; }
        for (int i = 5; i < N; i++) {
            v.push_back(v[i - 1] + v[i - 5]);
        }
        cout << v[N - 1] << '\n';
    }
}