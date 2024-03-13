#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int a, minv = INT32_MAX;
    cin >> a;
    int l1 = a / 5, l2 = a / 3;
    for (int i = 0; i <= l1; i++) {
        for (int j = 0; j <= l2; j++) {
            if (i * 5 + j * 3 == a) minv = min(minv, i + j);
        }
    }
    if (minv == INT32_MAX) cout << -1;
    else cout << minv;
    return 0;
}