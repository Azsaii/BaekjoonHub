#include <iostream>
#include <vector>
int v[1'000'001], lis[1'000'001];
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
    for (int i = 1; i < N; i++) {
        if (lis[cnt] < v[i]) lis[++cnt] = v[i];
        else {
            int s = 0, e = cnt;
            while (s < e) {
                int m = (s + e) / 2;
                if (lis[m] >= v[i]) e = m;
                else s = m + 1;
            }
            lis[e] = v[i];
        }
    }
    cout << ++cnt << '\n';
    return 0;
}