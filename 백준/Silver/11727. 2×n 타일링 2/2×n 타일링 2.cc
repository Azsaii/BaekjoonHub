#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<int> v(N);
    v[0] = 1; v[1] = 3;
    for (int i = 2; i < N; i++) {
        v[i] = (v[i - 1] + v[i - 2] * 2) % 10007;
    }
    cout << v[N - 1];
    return 0;
}