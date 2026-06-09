#include <climits>
#include <vector>

using namespace std;

int ret = INT_MAX;
void dfs(int a, int sum) {
	int n = a / 10;
	int t = a % 10;
	if (n == 0) {
		int s1 = sum + t;
		int s2 = sum + (10 - t) + 1;
		int tmp = s1 < s2 ? s1 : s2;
		if(ret > tmp) ret = tmp;
		return;
	}
	
	dfs(n, sum + t);
	dfs(n + 1, sum + (10 - t));
}

int solution(int storey) {
    dfs(storey, 0);
    return ret;
}