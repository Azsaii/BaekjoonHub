#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int N, a, b, res = 1;
    cin >> N;
    vector<pair<int, int>> v;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        v.push_back({ b, a });
    }
    sort(v.begin(), v.end());
    int ce = v[0].first;
    for (int i = 1; i < v.size(); i++) {
        auto [ne, nf] = v[i];
        if (ce > nf) continue;
        ce = ne;
        res++;
    }
    cout << res;
    return 0;
}