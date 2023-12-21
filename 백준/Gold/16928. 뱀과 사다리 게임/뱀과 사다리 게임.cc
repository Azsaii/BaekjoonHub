#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> snakeLadder(105, -1);
vector<bool> visited(101, false);
int res = INT_MAX;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

void bfs() {
    queue<pair<int, int>> q;
    q.push(make_pair(1, 0));
    visited[1] = true;

    while (!q.empty()) {
        int index = q.front().first;
        int cnt = q.front().second;
        q.pop();
        int maxIndex = 0;

        if (index == 100) {
            res = min(res, cnt);
            continue;
        }
        
        for (int i = 1; i <= 6; i++) {
            int nextIndex = index + i;
            if (nextIndex > 100 || visited[nextIndex]) continue;

            if (snakeLadder[nextIndex] != -1 && !visited[nextIndex]) { // 뱀이나 사다리가 있는 경우
                visited[nextIndex] = true;
                visited[snakeLadder[nextIndex]] = true;
                q.push(make_pair(snakeLadder[nextIndex], cnt + 1));
            }
            else maxIndex = max(maxIndex, nextIndex);
        }

        if (maxIndex != 0) { // 뱀이나 사다리 제외 가장 큰 칸 push
            visited[maxIndex] = true;
            q.push(make_pair(maxIndex, cnt + 1));
        }
    }
}

int main()
{
    init();
    int x, y, temp;
    
    cin >> x >> y;

    for (int i = 0; i < x + y; i++) {
        cin >> temp;
        cin >> snakeLadder[temp];
    }

    bfs();
    cout << res;
    return 0;
}