#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> edges;
vector<bool> visited;
void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}
void dfs(int node) {
    visited[node] = 1;
    for (int i = 0; i < edges[node].size(); i++) {
        int nxt = edges[node][i];
        if (!visited[nxt]) dfs(nxt);
    }
}
int countGroups() {
    int cnt = 0;
    for (int i = 1; i < visited.size(); i++) {
        if (!visited[i]) { dfs(i); cnt++; }
    }
    return cnt;
}
int main()
{
    init();
    int test_case, T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        int N, M, v1, v2;
        cin >> N >> M;
        edges = vector<vector<int>>(N + 1);
        visited = vector<bool>(N + 1, 0);
        for (int i = 0; i < M; i++) {
            cin >> v1 >> v2;
            edges[v1].push_back(v2);
            edges[v2].push_back(v1);
        }
        cout << "#" << test_case << " " << countGroups() << "\n";
    }
    return 0;
}