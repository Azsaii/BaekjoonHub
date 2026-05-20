#include <string>
#include <vector>
#include <unordered_set>
#include <cmath>
using namespace std;

vector<bool> visited;
vector<char> num;
unordered_set<int> set;
int len = 0;
int ret = 0;

bool isPrime(int a) {
	if (a <= 1) return false;
	if (a == 2 || a == 3) return true;
	int t = static_cast<int>(sqrt(a));
	for (int i = 2; i <= t; i++) {
		if (a % i == 0) return false;
	}

	return true;
}

void dfs(string cur) {
	if (cur.length() > 0) {
		int t = stoi(cur);
		if (set.find(t) == set.end()) {
			set.insert(t);
			if (isPrime(t)) ret++;
		}
	}

	for (int i = 0; i < len; i++) {
		if (visited[i] == false) {
			visited[i] = true;
			dfs(cur + num[i]);
			visited[i] = false;
		}
	}
}

int solution(string numbers) {
    len = numbers.length();
    visited.resize(len);
    for (int i = 0; i < len; i++) {
        num.push_back(numbers[i]);
    }
    dfs("");
    return ret;
}