#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int ret = 0;
    int sz = a.size() - 1;
    for (int i = sz; i >= 0; i--) {
        ret += a[i] * b[i];

    }
    return ret;
}