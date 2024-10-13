#include <bits/stdc++.h>
#define pii pair<int, int>
#define MAX 100000
using namespace std;
bool vst[100001];
int a, b, minv, cnt = 0;
void bfs() {
    queue<pii> q;
    q.push({ 0, a });
    while (!q.empty()) {
        auto [cv, cn] = q.front();
        q.pop();
        vst[cn] = 1;
        if (cv > minv) continue;
        if (cn == b) {
            if (cv < minv) { minv = cv; cnt = 1; }
            else cnt++;
            continue;
        }
        if (cn + 1 <= MAX && !vst[cn + 1]) q.push({ cv + 1, cn + 1 });
        if (cn * 2 <= MAX && !vst[cn * 2])  q.push({ cv + 1, cn * 2 });
        if (cn - 1 >= 0 && !vst[cn - 1]) q.push({ cv + 1, cn - 1 });
    }
}
int main() {
    cin >> a >> b;
    minv = abs(a - b);
    if (a > b) { cout << a - b << '\n' << 1; return 0; }
    bfs();
    cout << minv << '\n' << cnt;
}