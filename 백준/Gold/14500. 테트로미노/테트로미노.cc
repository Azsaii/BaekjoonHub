#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int arr[500][500];
int highest = 0, maxSum = 0;
vector<vector<bool>> visited(500, vector<bool>(500, false));

void dfs(int x, int y, int count, int sum, int n, int m) {
    if (count == 4) {
        maxSum = max(maxSum, sum);
        return;
    }

    if (sum + (4 - count) * highest <= maxSum) return;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny]) {
            visited[nx][ny] = true;
            dfs(nx, ny, count + 1, sum + arr[nx][ny], n, m);
            visited[nx][ny] = false;
        }
    }

    if (count == 1) {
        if (x > 0 && x < n - 1) {
            int tempSum = arr[x - 1][y] + arr[x][y] + arr[x + 1][y];
            if (tempSum + highest > maxSum) {
                if (y > 0) maxSum = max(maxSum, tempSum + arr[x][y - 1]);
                if (y < m - 1) maxSum = max(maxSum, tempSum + arr[x][y + 1]);
            }
        }
        if (y > 0 && y < m - 1) {
            int tempSum = arr[x][y - 1] + arr[x][y] + arr[x][y + 1];
            if (tempSum + highest > maxSum) {
                if (x > 0) maxSum = max(maxSum, tempSum + arr[x - 1][y]);
                if (x < n - 1) maxSum = max(maxSum, tempSum + arr[x + 1][y]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (highest < arr[i][j]) highest = arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = true;
            dfs(i, j, 1, arr[i][j], n, m);
            visited[i][j] = false;
        }
    }

    cout << maxSum;

    return 0;
}