#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int m, n, h; // 열, 행, 높이 
vector<int> box;
vector<bool> visited; // 각 노드의 방문 여부를 저장
int zeroCnt = 0;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int bfs(queue<int> q,int find[], int cnt) {
    int num = cnt;
    int res = 0;
    //cout << "t1" << "\n";
    while (!q.empty()) {
        int node = q.front();
        visited[node] = true;
        q.pop();
        num--;
        //cout << "pop: " << node << "\n";
        
        for (int i = 0; i < 6; i++) {
            int nextNode = node + find[i];
            if ((i == 0 || i == 1) && node / m != nextNode / m) continue; // 좌우로 움직일 때 행이 다르면 안된다.
            if ((i == 2 || i == 3) && node / (m * n) != nextNode / (m * n)) continue; // 상하로 움직일 때 층이 다르면 안된다.
            if (nextNode >= 0 && nextNode <= h * m * n - 1) { // 탐색중인 위치가 범위 내일 때
                if (box[nextNode] == 0 && !visited[nextNode]) { // 방문되지 않은 안 익은 토마토면
                    box[nextNode] = 1; // 익은 토마토로 변경
                    q.push(nextNode); // 큐에 익은 토마토 위치 넣기
                    visited[nextNode] = true; // 방문됨 표시
                    zeroCnt--;
                    //cout << "push: " << nextNode << "\n";
                }
            }
            //else cout << "@@@@@trash: " << nextNode << "\n";
        }

        if (num == 0) {
            res++;
            num = q.size();
            if (zeroCnt == 0) {
                //cout << "out\n";
                break;
            }
        }
    }

    return res;
}

int main()
{
    init();
    int t = -1, cnt = 0; 
    queue<int> q; // 익은 토마토만 들어가는 큐
    
    cin >> m >> n >> h;
    int find[6] = { -1, 1, -m, m, m * n * (-1), m * n }; // 좌, 우, 하, 상, 아래, 위

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> t;
                box.push_back(t);
                visited.push_back(false);
                if (t == 1) q.push(box.size() - 1);
                if (t == 0) zeroCnt++;
            }
        }
    }

    if (zeroCnt == 0) {
        cout << 0;
        return 0;
    }

    cnt = bfs(q, find, q.size());

    if (zeroCnt != 0) {
        cout << -1;
        return 0;
    }

    cout << cnt;
    return 0;
}