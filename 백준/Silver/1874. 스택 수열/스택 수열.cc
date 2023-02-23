#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 200000

typedef int element;
typedef struct {
	element data[MAX];
	int top;
}stack;

void init_stack(stack* s) {
	s->top = -1;
}
int is_empty(stack* s) {
	return (s->top == -1);
}
int is_full(stack* s) {
	return (s->top == MAX - 1);
}

void push(stack* s, element item) {
	if (is_full(s))
		return;
	else  s->data[++(s->top)] = item;
}
element pop(stack* s) {
	if (is_empty(s))
		return 0;
	else return s->data[(s->top)--];
}

element peek(stack* s) {
	if (is_empty(s))
		return 0;
	else return s->data[s->top];
}

int main() {
	stack s;
	init_stack(&s); //초기화
	int size = 0;
	int value = 0; // 입력받은 숫자
	int curNum = 1; // 스택에 들어갈 숫자
	char charArr[MAX] = { ' ', };
	int arrIndex = 0;
	int error = 0;
	scanf("%d", &size); // 받을 숫자의 수를 입력

	while (size-- > 0) {
		scanf("%d", &value);

		if (curNum <= value) {
			for (int i = curNum; i <= value; i++) {
				push(&s, i);
				charArr[arrIndex++] = '+';
			}
			curNum = value + 1;
		}

		else if (peek(&s) != value) {
			error = 1;
		}

		pop(&s);
		charArr[arrIndex++] = '-';
	}
	if (error == 1) {
		printf("NO");
		return 0;
	}
	for (int i = 0; i < arrIndex; i++) {
		printf("%c\n", charArr[i]);
	}
}