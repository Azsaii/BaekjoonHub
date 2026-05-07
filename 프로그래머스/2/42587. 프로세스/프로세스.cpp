#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#define ci pair<char, int>

using namespace std;

int solution(vector<int> priorities, int location) {
    char loc = location + 65;
    queue<ci> q;
    char c = 65;
    for (const auto& i : priorities) {
        q.push({ c++, i });
    }
    sort(priorities.begin(), priorities.end(), [](const int& a, const int& b) {return a > b; });

    int ret = 1;
    int maxv = priorities[0];
    while (!q.empty()) {
        auto [key, val] = q.front();
        if (val == maxv) {
            if (key == loc) {
                break;
            }
            q.pop();
            priorities[ret - 1] = -1;
            ret++;
            maxv = priorities[ret - 1];
        }
        else {
            q.pop();
            q.push({ key, val });
        }
    }
    return ret;
}