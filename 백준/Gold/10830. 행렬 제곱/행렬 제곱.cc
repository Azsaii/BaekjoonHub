#include <bits/stdc++.h>
#define MOD 1000
#define ll long long
#define vvs vector<vector<short>>
using namespace std;
ll m, cur;
int n;
vvs res(5, vector<short>(5)), tmp(5, vector<short>(5)), orig(5, vector<short>(5));
void mul(const vvs& a, const vvs& b, vvs& res) {
    vvs temp(5, vector<short>(5, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                temp[i][j] = (temp[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
            }
        }
    }
    res = temp;
}
void mp(vvs& base, ll exp) {
    vvs result(5, vector<short>(5, 0));
    for (int i = 0; i < n; i++) result[i][i] = 1; 
    while (exp > 0) {
        if (exp & 1) mul(result, base, result);
        mul(base, base, base);
        exp >>= 1;
    }
    res = result;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        cin >> orig[i][j]; res[i][j] = tmp[i][j] = orig[i][j];
    }
    mp(orig, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j] % MOD << ' ';
        }
        cout << '\n';
    }
}