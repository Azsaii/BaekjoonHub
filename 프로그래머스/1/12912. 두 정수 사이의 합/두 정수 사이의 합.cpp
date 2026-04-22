#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long cnt(long long t) {
    return t * (t + 1) / 2;
}

long long solution(int a, int b) {
   long long ret = 0;

    if (a > b) {
        int t = a;
        a = b;
        b = t;
    }

    int sum = a + b;
    int nums = b - a + 1;
    if (a == b) ret = a;
    else {
        ret = sum * (nums / 2);
        if (nums % 2 != 0) ret += (sum / 2);
    }

    return ret;
}
