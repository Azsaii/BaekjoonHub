#include <bits/stdc++.h>
#define NUM 601
using namespace std;
int findDist(string a, string b) {
    int res = 0;
    for (int i = 0; i < 4; i++) if (a[i] != b[i]) res++;
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
        int mode = 0;
        for (int i = 0; i < N; i++) {
            cin >> str;
            if (mode == 1) continue;
            if (vm[str] == 2) mode = 1;
            if (vm[str] != 2) {
                vm[str] += 1;
                v.push_back(str);
            }
        }
        if (mode == 1) { cout << "0\n"; continue; }
        int minv = INT32_MAX;
        int sz = v.size();
        vector<vector<int>> dist(sz, vector<int>(sz));
        for (int i = 0; i < sz - 1; i++) {
            for (int j = i + 1; j < sz; j++)
                dist[i][j] = findDist(v[i], v[j]);
        }
        for (int i = 0; i < sz - 1; i++) {
            for (int j = i + 1; j < sz - 1; j++) {
                for (int k = j + 1; k < sz; k++) {
                    minv = min(minv, dist[i][j] + dist[i][k] + dist[j][k]);
                }
            }
        }
        minv != INT32_MAX ? cout << minv << '\n' : cout << 0 << '\n';
    }
}