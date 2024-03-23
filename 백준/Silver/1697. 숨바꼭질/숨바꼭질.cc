#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int N, K, minv = INT32_MAX;
    cin >> N >> K;
    if (K <= N) { cout << N - K; return 0; }
    queue<pair<int, int>> q;
    unordered_map<int, int> m;
    q.push({ N, 0 });
    m[N] = 0;
    while (!q.empty()) {
        int cur = q.front().first, ii = q.front().second;
        q.pop();
        int arr[3] = { cur + 1, cur - 1, cur * 2 };
        for (int i = 0; i < 3; i++) {
            if (m.find(arr[i]) != m.end() && m[arr[i]] <= ii + 1) continue;
            if (arr[i] < 1 || arr[i] > K * 2) continue;
            m[arr[i]] = ii + 1;
            q.push({ arr[i], ii + 1 });
        }
    }
    cout << m[K];
    return 0;
}