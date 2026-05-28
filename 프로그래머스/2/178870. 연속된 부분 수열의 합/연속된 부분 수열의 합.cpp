#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> ret(2);
    int s = -1;
    int e = sequence.size() - 1;
    while (sequence[e] > k) e--;
    int sum = 0;

    for (int i = e; i >= 0; i--) {
        sum += sequence[i];
        if (sum == k) {
            s = i;
            break;
        }
        else if (sum > k) {
            sum -= sequence[e--];
        }
    }

    while (s > 0) {
        sum -= sequence[e--];
        sum += sequence[--s];
        if (sum != k) {
            ++s; ++e;
            break;
        }
    }
    ret[0] = s;
    ret[1] = e;
    return ret;
}