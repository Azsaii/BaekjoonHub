#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int a, maxv = 1000001; 
    cin >> a;
    vector<int> v(maxv, 0);
    for (int i = 2; i < maxv; i++) {
        v[i] = v[i - 1] + 1;
        if (i % 3 == 0) v[i] = min(v[i], v[i / 3] + 1);
        if (i % 2 == 0) v[i] = min(v[i], v[i / 2] + 1);
    }
    cout << v[a];
    return 0;
}