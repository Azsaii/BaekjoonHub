#include <queue>
#include <vector>
#include <algorithm>
#define pii pair<int, int>

using namespace std;

vector<int> solution(vector<string> maps) {
    int height = maps.size();
    int width = maps[0].size();
    vector<vector<bool>> vst(height, vector<bool>(width, 0));
    vector<int> ret;
    queue<pii> q;

    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    for (int i = 0; i < height; i++) {
        for (int k = 0; k < width; k++) {
            if (maps[i][k] != 'X' && vst[i][k] == 0) {
                int sum = 0;
                vst[i][k] = 1;
                q.push({ i, k });
                while (!q.empty()) {
                    auto [y, x] = q.front();
                    sum += (maps[y][x] - '0');
                    q.pop();
                    for (int t = 0; t < 4; t++) {
                        int nx = x + dx[t];
                        int ny = y + dy[t];
                        if(nx == width || nx < 0 || ny == height || ny < 0){}
                        else if(maps[ny][nx] != 'X' && vst[ny][nx] == 0){
                            vst[ny][nx] = 1;
                            q.push({ ny, nx });
                        }
                    }
                } 
                if(sum != 0) ret.push_back(sum);
            }
        }
    }
    sort(ret.begin(), ret.end());
    if (ret.size() == 0) ret.push_back(-1);
    return ret;
}