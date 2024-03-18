#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> v(n), sv;
    map<int, bool> m;
    for (int i = 0; i < n; i++) { cin >> v[i]; m[v[i]] = 1; }
    for (auto it : m) sv.push_back(it.first);
    int sz = sv.size();
    for (int i = 0; i < n; i++) {
        int s = 0, e = sz - 1, target = v[i];
        while (s <= e) {
            int mid = (s + e) / 2;
            if (sv[mid] == target) { cout << mid << ' '; break; }
            else if (sv[mid] < target) { s = mid + 1; }
            else if (sv[mid] > target) { e = mid - 1; }
        }
    }
    return 0;
}