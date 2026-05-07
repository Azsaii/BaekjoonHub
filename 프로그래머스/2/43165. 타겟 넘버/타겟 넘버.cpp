#include <string>
#include <vector>

using namespace std;

int ret = 0;
int target = 0;
size_t sz = 0;
vector<int> v;

void dfs(const int& num, const int& cnt) {
	if (cnt == sz && num == target) {
		ret++;
		return;
	}
	else if (cnt < sz) {
		dfs(num + v[cnt], cnt + 1);
		dfs(num - v[cnt], cnt + 1);
	}
}

int solution(vector<int> nums, int t) {
    v = nums;
    sz = v.size();
    target = t;
    dfs(0, 0);
    return ret;
}