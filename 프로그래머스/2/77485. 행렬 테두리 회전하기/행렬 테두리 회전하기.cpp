#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    int cnt = 1;
    vector<vector<int>> v(rows, vector<int>(columns));
    for (int i = 0; i < rows; i++) {
        for (int k = 0; k < columns; k++) {
            v[i][k] = cnt++;
        }
    }

    vector<int> ret;
    int dx[4] = { 1, 0, -1, 0 };
    int dy[4] = { 0, 1, 0, -1 };
    for (const auto& q : queries) {
        int last = -1;
        int w = q[3] - q[1];
        int h = q[2] - q[0];
        bool s = 0;
        int cx = q[1] - 1;
        int cy = q[0] - 1;
        int minv = v[cy][cx];
        for (int mode = 0; mode < 4; mode++) {
            int cur = w;
            if (s == 1) cur = h;
            for (int i = 0; i < cur; i++) {
                int nx = cx + dx[mode];
                int ny = cy + dy[mode];
                int nv = v[ny][nx];
                if (minv > nv) minv = nv;
                if (last != -1) v[ny][nx] = last;
                else v[ny][nx] = v[cy][cx];
                last = nv;
                cx = nx;
                cy = ny;
            }
            s = !s;
        }
        ret.push_back(minv);
    }
    return ret;
}