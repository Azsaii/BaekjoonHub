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
    vector<bool> mstSet(N, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int res = 0;

    pq.push({ 0, 0 }); // 가장 처음에는 0번 행성에서 시작
    key[0] = 0;

    while (!pq.empty()) {
        int u = pq.top().second; // 가장 가까운 정점 뽑기
        pq.pop();

        if (mstSet[u]) continue;
        mstSet[u] = true;

        res += key[u]; // u까지의 거리를 결과에 더함

        for (auto edge : edges[u]) { // u와 연결된 모든 행성에 대해
            int v = edge.second;
            int weight = edge.first;

            if (mstSet[v] == false && key[v] > weight) { // 더 가까운 거리가 발견되면 업데이트
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

    vector<int> sorted_x(N), sorted_y(N), sorted_z(N);
    for (int i = 0; i < N; i++) {
        sorted_x[i] = sorted_y[i] = sorted_z[i] = i;
    }

    auto compare_x = [&](int i, int j) { return p[i].x < p[j].x; };
    auto compare_y = [&](int i, int j) { return p[i].y < p[j].y; };
    auto compare_z = [&](int i, int j) { return p[i].z < p[j].z; };

    sort(sorted_x.begin(), sorted_x.end(), compare_x);
    sort(sorted_y.begin(), sorted_y.end(), compare_y);
    sort(sorted_z.begin(), sorted_z.end(), compare_z);

    for (int i = 0; i < N - 1; i++) {
        edges[sorted_x[i]].push_back({ abs(p[sorted_x[i]].x - p[sorted_x[i + 1]].x), sorted_x[i + 1] });
        edges[sorted_x[i + 1]].push_back({ abs(p[sorted_x[i]].x - p[sorted_x[i + 1]].x), sorted_x[i] });

        edges[sorted_y[i]].push_back({ abs(p[sorted_y[i]].y - p[sorted_y[i + 1]].y), sorted_y[i + 1] });
        edges[sorted_y[i + 1]].push_back({ abs(p[sorted_y[i]].y - p[sorted_y[i + 1]].y), sorted_y[i] });

        edges[sorted_z[i]].push_back({ abs(p[sorted_z[i]].z - p[sorted_z[i + 1]].z), sorted_z[i + 1] });
        edges[sorted_z[i + 1]].push_back({ abs(p[sorted_z[i]].z - p[sorted_z[i + 1]].z), sorted_z[i] });
    }

    cout << primMST();
    return 0;
}