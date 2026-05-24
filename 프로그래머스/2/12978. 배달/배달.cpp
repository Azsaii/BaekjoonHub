#include <queue>
#include <vector>
#include <climits>
#define pii pair<int, int>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    vector<pii> dist[51];
    for (const auto& v : road) {
        dist[v[0]].push_back({ v[1], v[2] });
        dist[v[1]].push_back({ v[0], v[2] });
    }
    vector<int> minDist(51, INT_MAX);
    minDist[1] = 0;
    
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({ 0, 1 });
    while (!pq.empty()) {
        const auto [key, val] = pq.top();
        pq.pop();
        
        if (minDist[val] < key) continue;

        for (const auto& v : dist[val]) {
            int cost = key + v.second;
            if (minDist[v.first] > cost) {
                minDist[v.first] = cost;
                pq.push({ cost, v.first });
            }
        }
    }

    int ret = 0;
    for (int i = 1; i <= N; i++) {
        if (minDist[i] <= K) ret++;
    }
    return ret;
}