#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_QUEUE_SIZE 100001
typedef int element;
typedef struct { // 큐 타입
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} DequeType;

// 초기화 
void init_deque(DequeType* q)
{
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(DequeType* q)
{
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(DequeType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 원형큐 출력 함수
int deque_print(DequeType* q, bool rev)
{
	int i;
	if (rev) i = q->front;
	else i = q->rear;
	printf("[");

	while (!is_empty(q) && rev) { // 정방향 
		i = (i + 1) % (MAX_QUEUE_SIZE);
		printf("%d", q->data[i]);
		if (i == q->rear)
			break;
		else printf(",");
	}

	while (!is_empty(q) && !rev) { // 역방향
		i = i % (MAX_QUEUE_SIZE);
		if (i == q->front)
			break;
		printf("%d", q->data[i]);
		i--;
		if(i != q->front) printf(",");
	}

	printf("]");
}

void add_rear(DequeType* q, element item)
{
	if (is_full(q)) return;
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

int delete_rear(DequeType* q, int cnt)
{
	if (is_empty(q) || q->rear - cnt < q->front) { // error
		return 1;
	}
	q->rear = (q->rear - cnt + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return 0;
}

void add_front(DequeType* q, element val)
{
	if (is_full(q)) return 0;
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

int delete_front(DequeType* q, int cnt)
{
	if (is_empty(q) || (q->front + cnt) % MAX_QUEUE_SIZE > q->rear) { // error
		return 1;
	}
	q->front = (q->front + cnt) % MAX_QUEUE_SIZE;
	return 0;
}

int main() {
	int count = 0, check = 0, cnt = 0, index = 0, d = 0;
	int arrSize = 0, num = 0;
	char tmp = '0';
	bool rev = true; // 방향 표시. true면 정방향 false면 역방향
	scanf("%d", &count);

	for (int i = 0; i < count; i++) {
		DequeType* dq = (DequeType*)malloc(sizeof(DequeType));
		init_deque(dq);
		rev = true; check = 0; cnt = 0;
		getchar();

		// 명령어를 입력받는다.
		char ins[MAX_QUEUE_SIZE] = { '0', }; 
		scanf("%s", ins);
	
		tmp = '0';
		scanf("%d", &arrSize); getchar(); // 배열 크기를 입력받는다.
		
		while (tmp != ']') { // 숫자 배열 받아서 덱에 입력
			scanf("%c", &tmp);
			if ((tmp == '[' || tmp == ',') && arrSize != 0) {
				scanf("%d", &num);
				add_rear(dq, num);
			}
			else if (tmp == ']') break;
		}

		for (int k = 0; k < strlen(ins); k++) { // 함수 처리
			if (ins[k] != 'R' && ins[k] != 'D') break;
			if (ins[k] == 'R') { 
				if (rev) rev = false;
				else rev = true;
			}
			else if (ins[k] == 'D') {
				// R이 나올때 까지 D의 수 cnt를 구한다.
				while (ins[k] == 'D') { 
					cnt++;
					k++; // 다음 문자를 검사한다.
					if (k == strlen(ins)) break;
				}
				k--; 
				// check는 에러인지 판단. 0이면 정상, 1이면 에러			
				if (rev) check = delete_front(dq, cnt); // 정방향 삭제
				else check = delete_rear(dq, cnt); // 역방향 삭제
				if (check == 1) { // 에러 처리
					printf("error");
					break;
				}
				cnt = 0;
			}	
		}
	
		if (check == 0) deque_print(dq, rev); // 함수 결과 표시
		printf("\n");
		free(dq);
	}
}