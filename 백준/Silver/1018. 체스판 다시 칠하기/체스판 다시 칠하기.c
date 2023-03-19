#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 50

int main()
{
    int m = 0, n = 0; // m이 가로, n이 세로
    char tmp = '0';
    scanf("%d %d", &n, &m);

    char map[MAX][MAX] = { '0',};
    int check[MAX][MAX] = { 2, };

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            scanf("%c", &tmp);
            if (tmp == '\n') k--;
            else if (tmp != '\n') {
                map[i][k] = tmp;
            }
        }
    }

    // cntB와 cntW는 둘 중 더 작은 수가 고쳐야 할 칸의 수이다.
    // cntB와 cntW의 합은 항상 8 * 8 = 64이다. 정상적인 경우에, 한 쪽 값은 64, 다른 한 쪽은 0이 된다.

    int cntB = 0;
    int cntW = 0;
    int min = MAX;

    for (int i = 0; i < n - 7; i++) { 
        for (int k = 0; k < m - 7; k++) {              
            cntB = 0; 
            cntW = 0;

            for (int x = i; x < i + 8; x++) { // 체스판의 첫 색이 검정색일 때 기준으로 고쳐야 할 칸의 수를 구한다.
                for (int y = k; y < k + 8; y++) {
                    if ((x + y) % 2 == 0) { // x, y 모두가 짝수이거나 모두가 홀수인 경우
                        if (map[x][y] == 'W') cntW++; 
                        else cntB++;
                    }
                    else {
                        if (map[x][y] == 'W') cntB++;
                        else cntW++;
                    }
                }
            }

            min = min < cntB ? min : cntB;
            min = min < cntW ? min : cntW;
        }
    }
    printf("%d", min);
}