#include <string>
#include <vector>

using namespace std;

int solution(int num, int lim, int p) {
    int ret = 0;
    vector<int> v(num + 1, 1);
    for (int i = 2; i <= num; i++) {
        for (int k = 1; ; k++) {
            int mul = i * k;
            if (mul > num) break;
            v[mul]++;
        }
    }

    for (int i = 1; i <= num; i++) {
        if (v[i] > lim) ret += p;
        else ret += v[i];
    }
    return ret;
}