#include <bits/stdc++.h>
#define NUM 601
using namespace std;
int findDist(string a, string b, string c) {
    int res = 0;
    for (int i = 0; i < 4; i++) {
        if (a[i] != b[i]) res++;
        if (b[i] != c[i]) res++;
        if (c[i] != a[i]) res++;
    }
    return res;
}
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int T, N;
    cin >> T;
    string str;
    for (int tc = 0; tc < T; tc++) {
        cin >> N;
        vector<string> v;
        unordered_map<string, int> vm;
        bool mode = 0;
        for (int i = 0; i < N; i++) {
            cin >> str;
            if (mode == 1) continue;
            if (vm[str] == 2) mode = 1;
            else {
                vm[str] += 1;
                v.push_back(str);
            }
        }
        if (mode == 1) { cout << "0\n"; continue; }
        int minv = INT32_MAX;
        int sz = v.size();
        for (int i = 0; i < sz - 1; i++) {
            for (int j = i + 1; j < sz - 1; j++) {
                for (int k = j + 1; k < sz; k++) {
                    minv = min(minv, findDist(v[i], v[j], v[k]));
                }
            }
        }
        minv != INT32_MAX ? cout << minv << '\n' : cout << 0 << '\n';
    }
}