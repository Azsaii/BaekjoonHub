#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>    // qsort 함수가 선언된 헤더 파일
#define MAX 100000

typedef struct _QUESTION {
    int x;
    int y;
} Point;

int compare(const void* a, const void* b)    // 오름차순 비교 함수 구현
{
    Point num1 = *(Point*)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
    Point num2 = *(Point*)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

    if (num1.x < num2.x)    // a가 b보다 작을 때는
        return -1;      // -1 반환

    if (num1.x > num2.x)    // a가 b보다 클 때는
        return 1;       // 1 반환

    if (num1.x == num2.x) {
        if (num1.y < num2.y)    
            return -1;      

        if (num1.y > num2.y)    
            return 1;      
    }

    return 0;    
}

int main()
{
    int size = 0;
    scanf("%d", &size);
    Point p[MAX];

    for (int i = 0; i < size; i++) {
        scanf("%d %d", &p[i].x, &p[i].y);
    }

    // 정렬할 배열, 요소 개수, 요소 크기, 비교 함수를 넣어줌
    qsort(p, size, sizeof(Point), compare);

    for (int i = 0; i < size; i++)
    {
        printf("%d %d\n", p[i].x, p[i].y);   
    }

    return 0;
}