#include <iostream>
#include <vector>
int v[1'000'001], lis[1'000'001], idx[1'000'001];
using namespace std;
void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}
int main() {
    init();
    int N, cnt = 0;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> v[i];
    lis[0] = v[0];
    idx[0] = 0;
    for (int i = 1; i < N; i++) {
        if (lis[cnt] < v[i]) {
            lis[++cnt] = v[i];
            idx[i] = cnt;
        }
        else {
            int s = 0, e = cnt;
            while (s < e) {
                int m = (s + e) / 2;
                if (lis[m] >= v[i]) e = m;
                else s = m + 1;
            }
            lis[e] = v[i];
            idx[i] = e;
        }
    }
    cout << ++cnt << '\n';
    vector<int> res;
    for (int i = N - 1, j = cnt - 1; i >= 0; i--) {
        if (idx[i] == j) {
            res.push_back(v[i]);
            j--;
        }
    }
    for (int i = res.size() - 1; i >= 0; i--) cout << res[i] << ' ';
    return 0;
}