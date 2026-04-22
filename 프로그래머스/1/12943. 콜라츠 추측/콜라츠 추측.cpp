#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    long long n = static_cast<long long>(num);
    long long ret = 0;

    while (n != 1) {
        if (n % 2 == 0) n /= 2;
        else n = n * 3 + 1;
        ret++;

        if (ret == 501) {
            ret = -1;
            break;
        }
    }
    return ret;
}