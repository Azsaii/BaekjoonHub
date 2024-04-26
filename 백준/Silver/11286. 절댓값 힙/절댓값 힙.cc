#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int N, x;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    cin >> N;
    while (N--) {
        cin >> x;
        if (x == 0) {
            if (!pq.empty()) { cout << pq.top().second << '\n'; pq.pop(); }
            else cout << "0\n";
        }
        else pq.push({ abs(x), x });
    }
}