#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_QUEUE_SIZE 1000000

typedef struct {
	int x;
	int y;
} Point;

typedef struct { // 큐 타입
	Point* queue;
	int front, rear;
} QueueType;

// 공백 상태 검출 함수
void queue_init(QueueType* q)
{
	q->queue = (Point*)malloc(sizeof(Point) * MAX_QUEUE_SIZE);
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 삽입 함수
void enqueue(QueueType* q, int x, int y)
{
	if (is_full(q)) return;
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear].x = x;
	q->queue[q->rear].y = y;
	return;
}

// 삭제 함수
Point dequeue(QueueType* q)
{
	if (is_empty(q)) return;
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

#define MAX_VERTICES 1000
typedef struct GraphType {
	int n;	// 정점의 개수
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

// 그래프 초기화 
void graph_init(GraphType* g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 9;
	return;
}

int bfs_mat(GraphType* g, Point* start, int n, int m, int index, int blank)
{
	int time = 0; // 걸리는 시간
	int count = 0; // 오늘 익을 토마토 수
	int next = 0; // 내일 익을 토마토 수
	int total = m * n - blank; // 전체 토마토의 수
	QueueType q;
	Point v;

	queue_init(&q);     // 큐 초기화 

	for (int i = 0; i < index; i++) {
		enqueue(&q, start[i].x, start[i].y);		// 시작 정점을 큐에 저장
		count++;
	}

	while (!is_empty(&q)) {
		v = dequeue(&q);		// 익지 않은 토마토를 검사하기 위한 익은 토마토의 위치를 뽑아낸다.
		count--; // 오늘 익을 토마토의 숫자를 줄인다.
		total--; // 익지 않은 토마토의 숫자를 줄인다.
		if (total != 0 && count == 0) time++;

		// 익은 토마토의 상하좌우를 탐색해서 안 익은 토마토를 1로 바꾼다.
		if (v.x != 0 && g->adj_mat[v.x - 1][v.y] == 0) { // 상
			g->adj_mat[v.x - 1][v.y] = 1;
			enqueue(&q, v.x - 1, v.y);
			next++;
		}
		if (v.x + 1 != m && g->adj_mat[v.x + 1][v.y] == 0) { // 하
			g->adj_mat[v.x + 1][v.y] = 1;
			enqueue(&q, v.x + 1, v.y);
			next++;
		}
		if (v.y != 0 && g->adj_mat[v.x][v.y - 1] == 0) { // 좌
			g->adj_mat[v.x][v.y - 1] = 1;
			enqueue(&q, v.x, v.y - 1);
			next++;
		}
		if (v.y + 1 != n && g->adj_mat[v.x][v.y + 1] == 0) { // 우
			g->adj_mat[v.x][v.y + 1] = 1;
			enqueue(&q, v.x, v.y + 1);
			next++;
		}

		if (is_empty(&q) && next == 0) {
			if (total != 0) return -1; // 토마토가 모두 익지 못하는 경우
			break; // 토마토가 모두 익은 경우
		}

		if (count == 0) { // 날짜를 세기 위한 처리
			count = next;
			next = 0;
		}
	}
	return time;
}

int main(void)
{
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	graph_init(g);

	int m = 0, n = 0;
	int tmp = 0, check = 0, blank = 0, index = 0;
	scanf("%d %d", &n, &m);

	Point* start;
	start = (Point*)malloc(sizeof(Point) * m * n);

	for (int i = 0; i < m; i++) {
		for (int k = 0; k < n; k++) {
			scanf("%d", &g->adj_mat[i][k]);
			if (g->adj_mat[i][k] == -1) blank++;
			if (g->adj_mat[i][k] == 1) { // 탐색 시작지점 저장
				start[index].x = i;
				start[index].y = k;
				index++;
			}
		}
	}

	if (index == 0) {
		printf("-1");
		return 0;
	}

	printf("%d", bfs_mat(g, start, n, m, index, blank));
	free(g);
	free(start);
	return 0;
}
