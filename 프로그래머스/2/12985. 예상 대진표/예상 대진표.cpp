#include <iostream>
#include <algorithm>
using namespace std;

int solution(int n, int a, int b)
{
    if (a > b) swap(a, b);

    int ret = 1;
    while (n) {
        if (b % 2 == 0 && a % 2 == 1 && b - a == 1) break;
        
        a++;
        a >>= 1;
        b++;
        b >>= 1;
        ret++;
        n >>= 1;
    }
    
    return ret;
}