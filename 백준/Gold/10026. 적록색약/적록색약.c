#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int visited[MAX][MAX] = {0, }; // 방문됨을 표시할 배열
int graph[MAX][MAX] = {0, }; // RGB 표시할 배열
int size = 0; // 그래프의 사이즈

int ax[] = { 1, -1, 0, 0 }; 
int ay[] = { 0, 0, 1, -1 };

void dfs(int x, int y) {
	int check = graph[x][y]; // 색 알아내기
	visited[x][y] = 1; // 방문 표시
	
	for (int i = 0; i < 4; i++) {
		// x, y로부터 인접한 좌표의 RGB가 같은지 검사
		int cx = x + ax[i];
		int cy = y + ay[i];

		// 그래프의 범위를 벗어나는 좌표는 검사하지 않는다.
		if (cx >= size || cy >= size || cx < 0 || cy < 0) continue;

		if (graph[cx][cy] == check && !visited[cx][cy]) dfs(cx, cy);
	}
}

int main() {	
	scanf("%d", &size);
	getchar();
	char c;
	int nomal = 0;
	int abnomal = 0;

	for (int i = 0; i < size; i++) {
		for (int k = 0; k < size; k++) {
			scanf("%c", &c);
			if (c == 'R') graph[i][k] = 1;
			else if (c == 'G') graph[i][k] = 2;
			else if (c == 'B') graph[i][k] = 3;
		}
		getchar(); // 엔터 칠떄 들어가는 문자 제거
	}
	
	for (int i = 0; i < size; i++) {
		for (int k = 0; k < size; k++) {
			if (!visited[i][k]) { // 정상인 경우 검사
				nomal++;
				dfs(i, k);
			}	
		}
	}
	
	for (int i = 0; i < size; i++) {
		for (int k = 0; k < size; k++) {
			visited[i][k] = 0; // visited 배열 초기화
			if (graph[i][k] == 2) graph[i][k] = 1; // 초록색을 빨간색으로 바꾼다.
		}
	}

	for (int i = 0; i < size; i++) {
		for (int k = 0; k < size; k++) {
			if (!visited[i][k]) { // 비정상인 경우 검사
				abnomal++;
				dfs(i, k);
			}	
		}
	}
	
	printf("%d %d", nomal, abnomal);
}
