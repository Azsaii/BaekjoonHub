#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int inf = INT_MAX;
vector<int> g(400, 0);
vector<int> dis(400, inf);
vector<int> fishPos;

int res = 0, fishCnt = 0, level = 2, levelCnt = 2, n;


void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int bfs(int startIndex, int desIndex) {
    queue<pair<int, int>> q; // 위치와 이동거리
    vector<bool> visited(400, false);
    q.push(make_pair(startIndex, 0));
    visited[startIndex] = true;
    int distance = inf;
    int findIndex[4] = { 1, -1, n, -n };
    //cout << "startIndex: " << startIndex << ", desIndex: " << desIndex << "\n";

    while (!q.empty()) {
        int node = q.front().first;
        int cnt = q.front().second;
        q.pop();
        // cout << "pop node: " << node << ", cnt: " << cnt << "\n";
        if (node == desIndex) {
            //cout << "arrived! node: " << node << ", cnt : " << cnt << "\n";
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
            //cout << "push nextNode " << nextNode << "\n";
        }
    }

    dis[desIndex] = distance;
    return distance; // 목적지까지 최단거리 반환
}

int updateDistance(int startIndex) {
    // bfs 여러번 돌려서 dis 업데이트
    int minDistance = inf, minFish = startIndex;
    for (int i = 0; i < fishCnt; i++) {
        if (g[fishPos[i]] >= level || g[fishPos[i]] == 0 || g[fishPos[i]] == 9) continue;
        
        int temp = bfs(startIndex, fishPos[i]);   
        if (minDistance > temp) { // 최단거리의 물고기 업데이트
            //cout << "bfs start - startIndex: " << startIndex << ", minFish = " << fishPos[i] << "minDis = " << minDistance << "\n";
            minFish = fishPos[i];
            minDistance = temp;  
        }
    }
    if(minDistance != inf) res += minDistance;

    return minFish;
}

void eat(int startIndex) {
    int cnt = fishCnt;
    while (cnt != 0) {
        // dis배열 for문돌려서 거리가장 가까운거 선택
        // 상어 레벨업, 물고기 먹음처리, res += 거리
        // startIndex 업데이트
        // 물고기 더 못먹으면 탈출
        int temp = updateDistance(startIndex);
        if (temp == startIndex) {
            //cout << "eat 탈출. res = " << res << "cnt: " << cnt << "\n";
            break;
        }
        else {
            //cout << "상어 이동 " << startIndex << " -> " << temp << " 현재 거리: " << res << "\n";
            g[startIndex] = 0;
            startIndex = temp;
            g[temp] = 9;

            cnt--;
            levelCnt--;
            if (levelCnt == 0) {
                level++;
                levelCnt = level;
            }

            //cout << "------------------------- 상어 레벨: " << level << "\n";
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
            dis[i] = inf;
            fishPos.push_back(i);
        }
    }

    eat(startIndex);
    cout << res;
    return 0;
}