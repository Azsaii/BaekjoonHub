#include<iostream>
#include<vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n, p, i, cnt, maxv, val, cur, prev, s;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cin >> n >> p;
        vector<int> diff;
        for (i = 0; i < n; i++) {
            cin >> cur;
            if (i == 0) {
                prev = cur;
                continue;
            }
            diff.push_back(cur - prev - 1);
            prev = cur;
        }
        cnt = 1; maxv = 1; val = 0; s = 0;
        for (i = 0; i < diff.size(); i++) {
            int temp = val + diff[i];
            if (temp <= p) { val = temp; cnt++; }
            else {
                i--;
                cnt--;
                val -= diff[s++];
            }
            if (maxv < cnt) maxv = cnt;
        }
        cout << "#" << tc << ' ' << maxv + p << '\n';
    }
    return 0;
}