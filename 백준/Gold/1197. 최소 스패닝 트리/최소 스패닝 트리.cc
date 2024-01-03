#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 987654321
#define N 10000
typedef pair<int, int> Pos;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int main()
{
    init();
    int V, E, v, u, w;
    cin >> V >> E;
    vector<vector<Pos>> adj(V + 1); 
    for (int i = 0; i < E; i++) {
        cin >> v >> u >> w;
        adj[u].push_back(Pos(w, v));
        adj[v].push_back(Pos(w, u));
    }
    priority_queue< Pos, vector <Pos>, greater<Pos> > pq;
    int src = 1, sum = 0;
    vector<int> key(V + 1, INF), parent(V + 1, -1);
    vector<bool> inMST(V + 1, 0);
    pq.push(make_pair(0, src));
    key[src] = INF;
    while (!pq.empty()) {
        int cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;
        for (int v = 0; v < adj[u].size(); v++) {   
            int weight = adj[u][v].first;
            int next = adj[u][v].second;
            if (inMST[next] == false && key[next] > weight) {
                key[next] = weight;
                pq.push(make_pair(key[next], next));
                parent[next] = u;
            }
        }
    }
    for (int i = 0; i <= V; i++) {
        if (key[i] != INF) sum += key[i];
    }
    cout << sum;
    return 0;
}