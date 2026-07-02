#include <string>
#include <vector>

using namespace std;

vector<vector<int>> ret;

void f(int n, int from, int to, int by) {
    if (n == 1) {
        ret.push_back({ from, to });
        return;
    }
    f(n - 1, from, by, to);
    ret.push_back({ from, to });
    f(n - 1, by, to, from);
}

vector<vector<int>> solution(int n) {
    f(n, 1, 3, 2);
    return ret;
}