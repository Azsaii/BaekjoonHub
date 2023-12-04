#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int n, t, s;
    int cnt = 0;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int s = 1;
        cin >> t;
        for (int k = 2; k < t; k++) {
            if (t % k == 0) {
                s = 0;
                break;
            }
        }
        if (s == 1 && t != 1) cnt++;
    }
    cout << cnt;
}