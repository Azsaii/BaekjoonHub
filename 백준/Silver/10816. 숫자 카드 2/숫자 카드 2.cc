#include<bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int N, M, t;
    cin >> N;
    unordered_map<int, int> m;
    for (int i = 0; i < N; i++) { cin >> t; if (m.find(t) == m.end())m[t] = 1; else m[t]++; }
    cin >> M;
    vector<int> res(M);
    for (int i = 0; i < M; i++) { cin >> t; res[i] = m[t]; }
    for (int i = 0; i < M; i++) cout << res[i] << ' ';
    return 0;
}