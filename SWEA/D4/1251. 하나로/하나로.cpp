#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#define INF 1e18
using namespace std;
void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}
struct Pos { int x, y; };
long long calc(Pos p1, Pos p2) {
    return pow(abs(p1.x - p2.x), 2) + pow(abs(p1.y - p2.y), 2);
}
int main()
{
    init();
    int test_case, T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        int N, temp;
        double E;
        long long res = 0;
        cin >> N;
        vector<Pos> vp(N);
        vector<long long>dist(N, INF);
        vector<bool> visited(N, 0);
        for (auto &it: vp) cin >> it.x;
        for (auto &it: vp) cin >> it.y;
        cin >> E;
        int cur = 0;
        visited[cur] = 1;
        while(1) {
            int nxt = -1;
            for (int j = 0; j < N; j++) dist[j] = min(dist[j], calc(vp[j], vp[cur]));
            for (int j = 0; j < N; j++) {
                if (visited[j]) continue;
                if (nxt == -1 || dist[nxt] > dist[j]) nxt = j;
            }
            if (nxt == -1) break;
            res += dist[nxt];
            visited[nxt] = 1;
            cur = nxt;
        }
        cout << "#" << test_case << " " << fixed << setprecision(0) << res * E << "\n";
    }
    return 0;
}