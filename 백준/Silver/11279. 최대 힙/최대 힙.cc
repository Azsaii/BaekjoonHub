#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int N, x;
    priority_queue<int> pq;
    cin >> N;
    while (N--) {
        cin >> x;
        if (x == 0) {
            if (!pq.empty()) { cout << pq.top() << '\n'; pq.pop(); }
            else cout << "0\n";
        }
        else pq.push(x);
    }
}