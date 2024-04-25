#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int N, cur = 1;
    cin >> N;
    vector<int> v(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        v[i] = v[i - 1] + 1;
        for (int j = 1; j * j <= i; j++)
            v[i] = min(v[i], v[i - j * j] + 1);
    }
    cout << v[N];
}