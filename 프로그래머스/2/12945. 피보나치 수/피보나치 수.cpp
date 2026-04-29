#include <string>
#include <vector>

using namespace std;

vector<int> v(100001, -1);

int calc(int t) {
    if (t == 0) return 0;
    else if (t == 1) return 1;
    else {
        int a = v[t - 1];
        int b = v[t - 2];
        if (a == -1) {
            a = calc(t - 1);
            v[t - 1] = a;
        }
        if (b == -1) {
            b = calc(t - 2);
            v[t - 2] = b;
        }

        return (a + b) % 1234567;
    }
}

int solution(int n) {
    int ret = calc(n);
    return ret;
}