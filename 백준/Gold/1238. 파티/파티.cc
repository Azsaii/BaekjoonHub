#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

#define pii pair<int, int>
#define mp make_pair
#define INF 987654321

int N, M, X;
vector<int> dist, rdist;
vector<vector<pair<int, int>>> adj, radj;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

void dijkstra(vector<vector<pii>>& graph, vector<int>& dist, int src) {
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    dist.assign(N + 1, INF);
    pq.push(mp(0, src));
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] != INF && dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(mp(dist[v], v));
            }
        }
    }
}

int main()
{
    init(); 
    int x, y, t, result = 0;
    
    cin >> N >> M >> X;
    
    adj.resize(N + 1);
    radj.resize(N + 1);

    for (int i = 0; i < M; i++) {
        cin >> x >> y >> t;
        adj[x].push_back({ y, t });
        if (x != X) radj[y].push_back({ x, t });
    }

    dijkstra(adj, dist, X);
    dijkstra(radj, rdist, X);

    for (int i = 1; i <= N; i++) {
        result = max(result, (dist[i] + rdist[i]));
    }
    
    cout << result;
    return 0;
}