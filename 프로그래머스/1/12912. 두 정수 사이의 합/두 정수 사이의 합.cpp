#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
   long long ret = 0;

    if (a > b) {
        int t = a;
        a = b;
        b = t;
    }

    long long sum = a + b;
    long long nums = b - a + 1;
    if (a == b) ret = a;
    else {
        ret = sum * (nums / 2);
        if (nums % 2 != 0) ret += (sum / 2);
    }

    return ret;
}
