#include <string>
#include <vector>
#include <queue>+
#define pii pair<int, int>
using namespace std;

int sz1 = -1;
int sz2 = -1;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int f(vector<string>& maps, int& sx, int& sy, char find) {
    vector<vector<int>> vst(sz1, vector<int>(sz2));
    queue<pii> q;
    q.push({ sy, sx });
    bool ch = false;
    while (!q.empty()) {
        const auto [cy, cx] = q.front();
        q.pop();
        int dist = vst[cy][cx]; 
        if (maps[cy][cx] == find) {
            sy = cy;
            sx = cx;
            ch = true;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (ny < 0 || ny >= sz1 || nx < 0 || nx >= sz2) {}
            else if(vst[ny][nx] == 0 && maps[ny][nx] != 'X'){
                vst[ny][nx] = dist + 1;
                q.push({ ny, nx });
            }
        }
    }
    if (ch == false) return -1;
    return vst[sy][sx];
}

int solution(vector<string> maps) {
    sz1 = maps.size();
    sz2 = maps[0].size();
    int sx = -1;
    int sy = -1;
    for (int i = 0; i < sz1; i++) {
        bool ch = false;
        for (int k = 0; k < sz2; k++) {
            if (maps[i][k] == 'S') {
                sy = i;
                sx = k;
                ch = true;
                break;
            }
        }
        if (ch) break;
    }
    int t1 = f(maps, sx, sy, 'L');
    if (t1 == -1) return -1;
    int t2 = f(maps, sx, sy, 'E');
    if(t2 == -1) return -1;
    
    return t1 + t2;
}