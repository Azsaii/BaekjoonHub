#include <cmath>
using namespace std;

long long solution(int w,int h) {
    if (w > h) swap(w, h);
    long long lh = static_cast<long long>(h);
    long long lw = static_cast<long long>(w);
    
    long long ret = 0;
    for (long long i = 1; i <= lw; i++) {
        long long y1 = lh * i;
        long long y2 = lh * (i - 1);
        long long a = y1 / lw;
        long long b = y2 / lw;
        if (y1 % lw != 0) ret++;
        if (y2 % lw != 0) {
            ret++;
            b++;
        }
        ret += (a - b);
    }

    return lw * lh - ret;
}