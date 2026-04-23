#include <string>
#include <cmath>

using namespace std;

int solution(string t, string p) {
    int ret = 0;
    int tsz = t.length();
    int psz = p.length();
    int sub = tsz - psz + 1;

    int a = psz - 1;
    long long ip = 0;
    for (int i = 0; i < psz; i++) {
        ip += (p[i] - 48) * pow(10, a--);
    }

    for (int i = 0; i < sub; i++) {
        a = psz - 1;
        long long tmp = 0;
        for (int k = i; k < i + psz; k++) {
            tmp += (t[k] - 48) * pow(10, a--);
        }
        
        if (tmp <= ip) ret++;
    }
    return ret;
}