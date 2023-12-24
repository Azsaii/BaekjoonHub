#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Pos {
    int x, y;
};

int inf = 987654321;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int main()
{
    init();
    Pos sp;
    int N, map[20][20], result = 0, size = 2, sizeCnt = 2;
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                sp = { i, j };
                map[i][j] = 0;
            }
        }
    }

    while (1) {
        bool visited[20][20] = { 0, };
        queue<Pos> q;
        q.push(sp);
        visited[sp.x][sp.y] = true;
        int dis = 0, minX, minY;
        minX = minY = inf;

        while (!q.empty()) {
            int qsize = q.size();
            dis++;
            while (qsize--) {
                Pos node = q.front();
                q.pop();
      
                for (int i = 0; i < 4; i++) {
                    int nx = node.x + dx[i];
                    int ny = node.y + dy[i];
                    if (nx < 0 || ny < 0 || nx == N || ny == N || map[nx][ny] > size || visited[nx][ny]) continue;
                    if (map[nx][ny] != 0 && map[nx][ny] < size) {
                        if (nx < minX) minX = nx, minY = ny; // 후보 물고기 갱신
                        else if (nx == minX && ny < minY) minY = ny;
                    }
                    q.push({ nx, ny });
                    visited[nx][ny] = true;
                }
            }
            if (minX != inf) {
                result += dis;
                sp.x = minX, sp.y = minY; // 시작 지점 갱신
                map[sp.x][sp.y] = 0;
                sizeCnt--; 
                if (sizeCnt == 0) size++, sizeCnt = size; // 상어 사이즈 증가
                break;
            }
        }
        if (minX == inf) break;
    }

    cout << result;
    return 0;
}