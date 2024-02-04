#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
#define pii pair<int, int>
void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}
int main() {
    init();
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int N, K, t;
        cin >> N;
        int arr[11];
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        unordered_map<int, int> m;
        for (int i = 0; i < N; i++) {
            cin >> t;
            arr[i] = t;
        }
        cin >> K;
        pq.push({ 0, K });
        m[K] = 0;
        while (!pq.empty()) {
            pii top = pq.top();
            if (top.second == 0) break;
            pq.pop();
            if (m[top.second] < top.first) continue;
            for (int i = 0; i < N; i++) {
                int cnt = top.first + top.second % arr[i];
                int divk = top.second / arr[i];
                if (m[divk] > cnt || m[divk] == 0) {
                    pq.push({ cnt, divk });
                    m[divk] = cnt;
                }
            }
        }
        cout << "#" << tc << " " << pq.top().first << "\n";
    }
    return 0;
}