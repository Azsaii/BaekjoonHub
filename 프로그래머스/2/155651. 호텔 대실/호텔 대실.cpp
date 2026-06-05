#include <string>
#include <vector>
#include <algorithm>
#define pib pair<int, bool>
using namespace std;

int solution(vector<vector<string>> book_time) {
    vector<pib> time;
    for (const auto& v : book_time) {
        int h1 = stoi(v[0].substr(0, 2));
        int m1 = stoi(v[0].substr(3, 2));
        int h2 = stoi(v[1].substr(0, 2));
        int m2 = stoi(v[1].substr(3, 2));
        time.push_back({ h1 * 60 + m1, 0 });
        time.push_back({ h2 * 60 + m2 + 9, 1 });
    }

    int maxv = 0;
    int cnt = 0;
    sort(time.begin(), time.end());
    for (const auto& v : time) {
        if (v.second == 0)cnt++;
        else cnt--;
        if (maxv < cnt) maxv = cnt;
    }
    return maxv;
}