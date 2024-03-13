#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int a, b, sum = 0;
    cin >> a;
    deque<int> dq;
    for (int i = 0; i < a; i++) { 
        cin >> b;
        if (b == 0) dq.pop_back();
        else dq.push_back(b);
    }
    while (!dq.empty()) { sum += dq.back(); dq.pop_back(); }
    cout << sum;
    return 0;
}