#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 100000001
#define pii pair<int, int>

int main() {
	int N, M, S, E;
	cin >> N >> M;

	vector<int> mv(N, INF);
	vector<vector<pii>> distance(N);
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		distance[a - 1].push_back({ b - 1, c });
	}

	cin >> S >> E;

	mv[S - 1] = 0;
	pq.push({ 0, S - 1 });

	while (!pq.empty()) {
		auto it = pq.top();
		pq.pop();

		int node = it.second;
		if (it.first > mv[node])continue;

		int size = distance[node].size();
		for (int i = 0; i < size; i++) {
			int nextNode = distance[node][i].first;
			int dist = it.first + distance[node][i].second;
			if (mv[nextNode] > dist) {
				mv[nextNode] = dist;
				pq.push({ dist, nextNode });
			}
		}
	}
	
	cout << mv[E - 1];
}