#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<int> v(N + 1);
    v[1] = 1; v[2] = 2;
    for (int i = 3; i <= N; i++) {
        v[i] = v[i - 1] + v[i - 2];
        v[i] %= 10007;
    }
    cout << v[N];
    return 0;
}