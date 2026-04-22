#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long ret = -1;
    long long tmp = n;
    int cnt = 0;
    
    while (tmp != 0) {
        cnt++;
        tmp /= 10;
    }

    int start = pow(10, cnt / 2 - 1);
    for (long long i = start; ; i++) {
        long long t = i * i;
        if(t > n) break;
        if (t == n) {
            i++;
            ret = i * i;
            break;
        }
    }
    
    return ret;
}