#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
#define INF 987654321

struct Pos {
    int x, y, z, i;
};
int N;
vector<Pos> p;
vector<vector<pair<int, int>>> edges;
void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}
int primMST() {
    vector<int> key(N, INF);
    vector<bool> mstSet(N, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int res = 0;
    pq.push({ 0, 0 }); 
    key[0] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (mstSet[u]) continue;
        mstSet[u] = 1;
        res += key[u];

        for (auto edge : edges[u]) { 
            int v = edge.second;
            int weight = edge.first;
            if (mstSet[v] == false && key[v] > weight) { 
                key[v] = weight;
                pq.push({ key[v], v });
            }
        }
    }
    return res;
}
int main()
{
    init();
    cin >> N;

    p.resize(N);
    edges.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> p[i].x >> p[i].y >> p[i].z;
        p[i].i = i;
    }

    vector<int> x(N), y(N), z(N);
    for (int i = 0; i < N; i++) {
        x[i] = y[i] = z[i] = i;
    }

    auto compare = [&](int i, int j, auto member) { return member(p[i]) < member(p[j]); };
    auto calc = [&](int i, int j, auto member) {
        int distance = abs(member(p[i]) - member(p[j]));
        edges[i].push_back({ distance, j });
        edges[j].push_back({ distance, i });
    };

    sort(x.begin(), x.end(), [&](int i, int j) { return compare(i, j, [](const Pos& p) { return p.x; }); });
    sort(y.begin(), y.end(), [&](int i, int j) { return compare(i, j, [](const Pos& p) { return p.y; }); });
    sort(z.begin(), z.end(), [&](int i, int j) { return compare(i, j, [](const Pos& p) { return p.z; }); });
    for (int i = 0; i < N - 1; i++) {
        calc(x[i], x[i + 1], [](const Pos& p) { return p.x; });
        calc(y[i], y[i + 1], [](const Pos& p) { return p.y; });
        calc(z[i], z[i + 1], [](const Pos& p) { return p.z; });
    }

    cout << primMST();
    return 0;
}