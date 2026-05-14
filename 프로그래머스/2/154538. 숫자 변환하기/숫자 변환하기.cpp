#include <unordered_map>
#include <vector>

using namespace std;

int x = 0;
int n = 0;
int ret = -1;
unordered_map<int, int> m;

void dfs(int y, int cnt) {
	if (y < x) return;
	if (y == x) {
		if (ret == -1 || ret > cnt) ret = cnt;
		return;
	}

	int a = y / 3;
	int b = y / 2;
	int c = y - n;

	if (y % 3 == 0 && (m[a] == 0 || m[a] > cnt + 1)) {
        m[a] = cnt + 1;
        dfs(a, cnt + 1);
    }
    if (y % 2 == 0 && (m[b] == 0 || m[b] > cnt + 1)) {
        m[b] = cnt + 1;
        dfs(b, cnt + 1);
    }
    if (c >= x && (m[c] == 0 || m[c] > cnt + 1)) {
        m[c] = cnt + 1;
        dfs(c, cnt + 1);
    }
}

int solution(int a, int b, int c) {
    x = a;
    n = c;
    dfs(b, 0);
    return ret;
}