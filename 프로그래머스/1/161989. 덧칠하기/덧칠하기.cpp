#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> v) {
    int ret = 0;
    vector<bool> vis(n + 1);
    int sz = n + 1;
    for (int& i : v) {
        if (vis[i] == false) {
            int end = i + m;
            if (end > sz) end = sz;
            for (int k = i; k < end; k++) {
                vis[k] = true;
            }
            ret++;
        }

    }
    return ret;
}