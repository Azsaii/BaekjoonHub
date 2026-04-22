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

    for(int i = a; i <= b; i++){
        ret += i;
    }

    return ret;
}