#include <string>
#include <vector>

using namespace std;

int ret = 0;
int t = 0;
size_t sz = 0;
vector<bool> vis;

void dfs(int cnt, vector<vector<int>>& v) {

	if (ret < cnt) ret = cnt;

	for (size_t i = 0; i < sz; i++) {
		if (vis[i] == false && v[i][0] <= t) {
			vis[i] = true;
			t -= v[i][1];
			dfs(cnt + 1, v);
			t += v[i][1];
			vis[i] = false;
		}
	}
}

int solution(int k, vector<vector<int>> v) {
    sz = v.size();
    vis.resize(sz);
    t = k;
    dfs(0, v);
    return ret;
}