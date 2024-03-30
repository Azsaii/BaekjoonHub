#include <bits/stdc++.h>
#define NUM 601
using namespace std;
int findDist(int a, int b) {
    int calc = a ^ b, res = 0;
    while (calc > 0) {
        if (calc & 1) res++;
        calc >>= 1;
    }
    return res;
}
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int T, N;
    cin >> T;
    char alp[4] = { 'I', 'S', 'T', 'J' }, c;   
    unordered_map<char, int> m;
    for (int i = 0; i < 4; i++) m[alp[i]] = i;
    for (int tc = 0; tc < T; tc++) {
        cin >> N;
        vector<int> v, tv;
        unordered_map<int, int> vm;
        int mode = 0;
        for (int i = 0; i < N; i++) {
            int cur = 0; string str;
            if (mode == 1) { cin >> str; continue; }
            for (int j = 0; j < 4; j++) {
                cin >> c;
                if (m.find(c) != m.end()) cur = cur | (1 << m[c]);
            }
            if (vm[cur] == 2) mode = 1;
            if (vm[cur] == 0) {
                vm[cur] = 1;
                v.push_back(cur);
            }
            else if(vm[cur] == 1) {
                mode = 2;
                vm[cur] += 1;
                tv.push_back(cur);
            }
        }
        if (mode == 1) { cout << "0\n"; continue; }
        int minv = INT32_MAX;
        if (mode == 2) {
            for (int i = 0; i < tv.size(); i++) {
                for (int j = 0; j < v.size(); j++) {
                    if (tv[i] == v[j]) continue;
                    minv = min(minv, 2 * findDist(tv[i], v[j]));
                }
            }
        }
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