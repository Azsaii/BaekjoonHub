#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n, m, c1, c2, cnt = 0;
    int low, minv, lowv, val, temp;
    bool check = 0;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cin >> n >> m >> c1 >> c2;
        vector<int> arr(n);
        minv = INT32_MAX;
        for (int i = 0; i < n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        for (int i = 0; i < m; i++) {
            cin >> val;
            low = lower_bound(arr.begin(), arr.end(), val) - arr.begin();
            lowv = INT32_MAX; check = 0;
            if (low > 0 && low < n) {
                int t1 = abs(arr[low] - val);
                int t2 = abs(arr[low - 1] - val);
                temp = min(t1, t2);
                if (t1 == t2) check = 1;
            }
            else {
                if (low == n) temp = abs(arr[n - 1] - val);
                else if (low == 0) temp = abs(arr[0] - val);
            }
            if (minv > temp) {
                cnt = 1;
                minv = temp;
                if (check) cnt++;
            }
            else if (minv == temp) {
                cnt++;
                if (check) cnt++;
            }
        }
        cout << "#" << tc << ' ' << minv + abs(c1 - c2) << ' ' << cnt << '\n';
    }
    return 0;
}