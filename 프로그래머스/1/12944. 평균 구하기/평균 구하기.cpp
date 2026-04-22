#include <string>
#include <vector>

using namespace std;

double solution(vector<int> v) {
    double ret = 0;
    int sz = v.size();
    for (int i : v) ret += i;
    ret /= sz;
    return ret;
}