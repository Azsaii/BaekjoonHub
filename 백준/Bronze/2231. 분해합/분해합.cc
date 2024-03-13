#include<bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int a, i;
    cin >> a;
    for (i = a - 54; i <= a; i++) {
        int sum = 0, tmp = i;
        while (tmp != 0) {
            int b = tmp % 10;
            sum += b;
            tmp /= 10;
        }
        if (sum + i == a) break;
    }
    if (i > a) cout << 0;
    else cout << i;
    return 0;
}