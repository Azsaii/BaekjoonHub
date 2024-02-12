#include <iostream>
#include<vector>
#include<cmath>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n, m, k;
vector<ll> arr, tree, last;
void init(int node, int s, int e) {
    if (s == e) { 
        tree[node] = arr[s];
        last.push_back(node);
        return;
    }
    else {
        init(node * 2, s, (s + e) / 2);
        init(node * 2 + 1, (s + e) / 2 + 1, e);
        tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % MOD;
        return;
    }
}
void upd(int ii, int val) {
    tree[ii] = val;
    while (ii > 1) {
        int l, r;
        if (ii % 2 == 0) { l = ii; r = ii + 1; }
        else { l = ii - 1; r = ii; }
        tree[ii / 2] = tree[l] * tree[r] % MOD;
        ii /= 2;
    }
}
ll sum(int node, int s, int e, int l, int r) {
    if (l > e || r < s) return 1;
    else if (l <= s && e <= r) return tree[node];
    ll a = sum(node * 2, s, (s + e) / 2, l, r);
    ll b = sum(node * 2 + 1, (s + e) / 2 + 1, e, l, r);
    return (a * b) % MOD;
}
int main() {
    cin >> n >> m >> k;
    int sz = 1 << ((int)ceil(log2(n)) + 1);
    arr.resize(n); tree.resize(sz);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    init(1, 0, n - 1);
    int o, a, b, c = m + k;
    while (c--) {
        cin >> o >> a >> b;
        if (o & 1) {
            upd(last[a - 1], b);
            arr[a - 1] = b;
        }
        else cout << sum(1, 0, n - 1, a - 1, b - 1) << '\n';
    }
    return 0;
}