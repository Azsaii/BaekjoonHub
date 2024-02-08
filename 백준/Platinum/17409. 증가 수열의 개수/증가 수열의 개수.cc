#include <iostream>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll ft[11][100001];
int n, k, t;
void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}
// 0 ~ p 까지 위치에서 길이가 s인 부분 수열 구하기
ll sum(int p, int s) {
    if (!s) return 1;
    ll res = 0;
    while (p) {
        res = (res + ft[s][p]) % MOD;
        p -= p & -p;
    }
    return res;
}
// 펜윅 트리 업데이트
void udt(int p, int s, int v) {
    while (p <= n) {
        ft[s][p] = (ft[s][p] + v) % MOD;
        p += p & -p;
    }
}
int main() {
    init(); 
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> t;
        for (int j = 1; j <= k; j++) {
            udt(t, j, sum(t - 1, j - 1));
        }
    }
    cout << sum(n, k);
}