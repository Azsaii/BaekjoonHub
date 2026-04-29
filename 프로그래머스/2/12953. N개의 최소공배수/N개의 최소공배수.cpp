#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> v) {
    sort(v.begin(), v.end(), [](const int& a, const int& b) {
        return a > b;
        });
    int ret = v[0];
    while (1) {
        bool check = true;
        for (const int& i : v) {
            if (ret % i != 0) {
                check = false;
                break;
            }
        }
        if (check == true) break;
        else ret++;
    }
    return ret;
}