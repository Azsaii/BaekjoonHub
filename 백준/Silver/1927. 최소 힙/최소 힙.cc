#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int N, a;
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (N--) {
        cin >> a;
        if (a > 0) pq.push(a);
        else {
            if (!pq.empty()) {
                cout << pq.top() << '\n';
                pq.pop();
            }
            else cout << "0\n";
        }
    }
    return 0;
}