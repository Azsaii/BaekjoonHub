#include <iostream>
#define MOD 5000000
#define MAX 100001
using namespace std;
typedef long long ll;
ll ft[51][MAX];
int n, i, j, k, arr[MAX];
void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}
// 0 ~ p 까지 인덱스에서 길이가 s인 부분 수열 구하기
ll sum(int s, int p) {
    if (!s) return 1;
    ll res = 0;
    while (p) {
        res = (res + ft[s][p]) % MOD;
        p -= p & -p;
    }
    return res;
}
// 펜윅 트리 업데이트
void udt(int s, int p, ll v) {
    while (p <= MAX) {
        ft[s][p] = (ft[s][p] + v) % MOD;
        p += p & -p;
    }
}
int main() {
    init();
    cin >> n >> k;
    for (i = 1; i <= n; i++) cin >> arr[i];
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= k; j++) {
            udt(j, arr[i], sum(j - 1, arr[i] - 1));
        }
    }
    cout << sum(k, MAX);
}