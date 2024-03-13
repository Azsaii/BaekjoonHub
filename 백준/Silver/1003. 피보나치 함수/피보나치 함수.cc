#include<bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int T, t;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> t;
        if (t == 0) { cout << "1 0\n"; continue; }
        else if (t == 1) { cout << "0 1\n"; continue; }
        pair<int, int> prev = { 1, 0 }, cur = { 0, 1 }, tmp;
        for (int i = 2; i <= t; i++) {
            tmp = prev;
            prev = cur;
            cur = { cur.first + tmp.first, cur.second + tmp.second };
        }
        cout << cur.first << ' ' << cur.second << '\n';
    }
	return 0;
}