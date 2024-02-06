#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}
int main() {
    init();
    int N;
    cin >> N;
    vector<int> v(N), lis, idx(N), res;
    for (int i = 0; i < N; i++) cin >> v[i];
    lis.push_back(v[0]);
    idx[0] = 0;
    for (int i = 1; i < N; i++) {
        if (lis.back() < v[i]) {
            lis.push_back(v[i]);
            idx[i] = lis.size() - 1;
        }
        else {
            auto it = lower_bound(lis.begin(), lis.end(), v[i]);
            *it = v[i];
            idx[i] = distance(lis.begin(), it);
        }
    }
    for (int i = N - 1, j = lis.size() - 1; i >= 0; i--) {
        if (idx[i] == j) {
            res.push_back(v[i]);
            j--;
        }
    }
    cout << lis.size() << '\n';
    for (int i = res.size() - 1; i >= 0; i--) cout << res[i] << ' ';
    return 0;
}
