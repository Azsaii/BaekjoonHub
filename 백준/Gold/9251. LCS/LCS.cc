#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    string s1, s2;
    cin >> s1 >> s2;
    int sz1 = s1.length() + 1, sz2 = s2.length() + 1;
    vector<vector<int>> v(sz1, vector<int>(sz2));
    for (int i = 0; i < sz1; i++) {
        for (int j = 0; j < sz2; j++) {
            if (i == 0 || j == 0) v[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1]) v[i][j] = v[i - 1][j - 1] + 1;
            else v[i][j] = max(v[i - 1][j], v[i][j - 1]);
        }
    }
    cout << v[sz1 - 1][sz2 - 1];
}