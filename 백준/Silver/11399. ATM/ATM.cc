#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int N, sum = 0;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++)cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = 1; i < N; i++) { v[i] = v[i - 1] + v[i]; sum += v[i]; }
    cout << sum + v[0];
    return 0;
}