#include <string>
#include <vector>

using namespace std;

vector<int> ret(2, 0);

void quad(vector<vector<int>>& arr, int x, int y, int sz) {
	if (sz == 1) {
		ret[arr[y][x]]++;
		return;
	}

	int limX = x + sz;
	int limY = y + sz;
	int val = -1;
	int cnt = 0;
	bool check = false;
	for (int i = y; i < limY; i++) {
		for (int k = x; k < limX; k++) {
			if (val == arr[i][k]) {}
			else if (val == -1) val = arr[i][k];
			else {
				check = true;
				break;
			}
		}
		if (check) break;
	}

	if (check == false) ret[val]++;
	else {
		int half = sz / 2;
		quad(arr, x, y, half);
		quad(arr, x + half, y, half);
		quad(arr, x, y + half, half);
		quad(arr, x + half, y + half, half);
	}
}

vector<int> solution(vector<vector<int>> arr) {
    quad(arr, 0, 0, arr[0].size());
    return ret;
}