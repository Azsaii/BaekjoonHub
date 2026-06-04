#include <cmath>
#include <climits>
#include <vector>

using namespace std;

int total = 0;
int minv = INT_MAX;
vector<vector<int>> tree;
vector<bool> vst;

int cnt(int node) {
	vst[node] = 1;
	int sum = 1;
	for (const auto& i : tree[node]) {
		if (vst[i] == 0) sum += cnt(i);
	}
	int gap = abs(total - sum * 2);
	if (minv > gap) minv = gap;
	return sum;
}

int solution(int n, vector<vector<int>> wires) {
    total = n;
    tree.resize(n + 1);
    vst.assign(n + 1, 0);
    for (const auto& v : wires) {
        tree[v[0]].push_back(v[1]);
        tree[v[1]].push_back(v[0]);
    }
    cnt(1);
    return minv;
}