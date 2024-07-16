#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n, t;
    vector<int> maxv(3, -1), minv(3, INT32_MAX);
    vector<int> v1(3), v2(3);
    cin >> n;
    for (int i = 0; i < n; i++) {  
        for (int j = 0; j < 3; j++) {
            cin >> t;
            v1[j] = t; v2[j] = t;
            if (maxv[j] == -1) { maxv[j] = t, minv[j] = t; continue; }
            switch (j) {
            case 0: {
                v1[j] = t + max(maxv[0], maxv[1]);
                v2[j] = t + min(minv[0], minv[1]);
                break;
            }
            case 1: {
                v1[j] = t + max(max(maxv[0], maxv[1]), maxv[2]);
                v2[j] = t + min(min(minv[0], minv[1]), minv[2]);
                break;
            }
            case 2: {
                v1[j] = t + max(maxv[1], maxv[2]);
                v2[j] = t + min(minv[1], minv[2]);
                break;
            }
            }
        }
        for (int j = 0; j < 3; j++) { maxv[j] = v1[j], minv[j] = v2[j]; }
    }
    cout << max(max(maxv[0], maxv[1]), maxv[2]) << ' ';
    cout << min(min(minv[0], minv[1]), minv[2]);
}