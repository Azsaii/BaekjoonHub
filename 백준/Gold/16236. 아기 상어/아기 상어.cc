#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int inf = INT_MAX;
vector<int> g(400, 0);
vector<int> fishPos;
int res = 0, fishCnt = 0, level = 2, levelCnt = 2, n;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int bfs(int startIndex, int desIndex) { // 상어가 정해진 물고기를 먹으러 가는데 걸리는 최단거리 구하기
    queue<pair<int, int>> q; // 위치와 이동거리
    vector<bool> visited(400, false);
    q.push(make_pair(startIndex, 0));
    visited[startIndex] = true;
    int distance = inf;
    int findIndex[4] = { 1, -1, n, -n };

    while (!q.empty()) {
        int node = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (node == desIndex) {
            distance = min(distance, cnt);
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nextNode = node + findIndex[i];
            // 범위가 잘못되었거나 방문되었거나 상어보다 큰 물고기인 경우 탐색불가
            if (nextNode < 0 || nextNode >= n * n || ((i == 0 || i == 1) && node / n != nextNode / n)) continue;
            if (visited[nextNode] || g[nextNode] > level) continue;
            q.push(make_pair(nextNode, cnt + 1));
            visited[nextNode] = true;
        }
    }

    return distance;
}

int findMinFish(int startIndex) { // 먹을 수 있는 물고기 중 최단거리 물고기 구해서 반환
    int minDistance = inf, minFish = startIndex;
    for (int i = 0; i < fishCnt; i++) { // 물고기 수만큼 반복
        if (g[fishPos[i]] >= level || g[fishPos[i]] == 0 || g[fishPos[i]] == 9) continue;
        
        int temp = bfs(startIndex, fishPos[i]); // 후보 물고기를 먹는 데 걸리는 최단거리 구하기
        if (minDistance > temp) { // 최단거리 물고기 업데이트
            minFish = fishPos[i];
            minDistance = temp;  
        }
    }
    if(minDistance != inf) res += minDistance;

    return minFish;
}

void eat(int startIndex) { // 물고기 수만큼 최단거리 물고기 차례로 구해서 먹기
    int cnt = fishCnt;
    while (cnt != 0) {
        int temp = findMinFish(startIndex);
        if (temp == startIndex) {
            break;
        }
        else {
            g[startIndex] = 0;
            startIndex = temp;
            g[temp] = 9;

            cnt--;
            levelCnt--;
            if (levelCnt == 0) {
                level++;
                levelCnt = level;
            }
        }
    }
}

int main()
{
    init();
    int temp, startIndex = 0;
    
    cin >> n;

    for (int i = 0; i < n * n; i++) {
        cin >> temp;
        g[i] = temp;
        if (temp == 9) startIndex = i;
        else if (temp != 0) {
            fishCnt++;
            fishPos.push_back(i);
        }
    }

    eat(startIndex);
    cout << res;
    return 0;
}