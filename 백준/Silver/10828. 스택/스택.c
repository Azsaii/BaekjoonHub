#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10000

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
	else s->data[++(s->top)] = item;
}
element pop(stack* s) {
	if (is_empty(s))
		return -1;
	else return s->data[(s->top)--];
}

element peek(stack* s) {
	if (is_empty(s))
		return -1;
	else return s->data[s->top];
}

int main() {
	stack s;
	init_stack(&s); //초기화
	
	int size = 0;
	char order[100010];
	int n = 0;

	scanf("%d", &size);
	fgetc(stdin);

	for (int i = 0; i < size; i++) {	
		scanf("%s", order);
		fgetc(stdin);

		if (strcmp(order, "pop") == 0) {
			printf("%d\n", pop(&s));
		}

		else if (strcmp(order, "size") == 0) {
			printf("%d\n", s.top + 1);
		}

		else if (strcmp(order, "empty") == 0) {
			if (is_empty(&s)) printf("1\n");
			else printf("0\n");
		}

		else if (strcmp(order, "top") == 0) {
			printf("%d\n", peek(&s));
		}

		else if (strcmp(order, "push") == 0) {
			scanf("%d", &n);
			push(&s, n);
		}
	}
}
