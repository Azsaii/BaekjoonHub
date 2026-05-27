#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> tmp(n * n, 0);
    int dx[3] = { 0, 1, -1 };
    int dy[3] = { 1, 0, -1 };
    int mode = 0;
    int lim = n * (n + 1) / 2;
    int cx = 0;
    int cy = 0;
    tmp[0] = 1;
    for (int i = 2; i <= lim; i++) {
        int nx = cx + dx[mode];
        int ny = cy + dy[mode];
        if (ny == n || nx == n || tmp[ny * n + nx] != 0) {
            mode = (mode + 1) % 3;
            nx = cx + dx[mode];
            ny = cy + dy[mode];
        }
        tmp[ny * n + nx] = i;
        cx = nx;
        cy = ny;
    }

    vector<int> ret;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k <= i; k++) {
            ret.push_back(tmp[i * n + k]);
        }
    }
    return ret;
}