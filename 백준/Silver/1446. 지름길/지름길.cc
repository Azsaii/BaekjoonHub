#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

constexpr int MAXN = 10001;
constexpr int INF = 1e9;
int N, D;

vector<pair<int, int>> graph[MAXN];
int dist[MAXN];

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> D;

    for (int i = 0; i < N; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        if (B - A > C && B <= D) { // 유효한 지름길만 추가
            graph[A].push_back(make_pair(B, C));
        }
    }

    fill(dist, dist + MAXN, INF);
    dist[0] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (cost > dist[now]) continue;

        for (auto &next : graph[now]) {
            int nextNode = next.first;
            int nextCost = cost + next.second;
            if (nextCost < dist[nextNode]) {
                dist[nextNode] = nextCost;
                pq.push({nextCost, nextNode});
            }
        }

        // 고속도로를 그냥 따라가는 경우
        if (now + 1 <= D && cost + 1 < dist[now + 1]) {
            dist[now + 1] = cost + 1;
            pq.push({cost + 1, now + 1});
        }
    }

    cout << dist[D];
    return 0;
}

