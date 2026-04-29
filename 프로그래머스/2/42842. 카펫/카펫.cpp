#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int sum = brown + yellow;
    int w = 0;
    int h = 0;
    for (int i = yellow; i > 0; i--) {
        if (yellow % i == 0) {
            int t = yellow / i;
            if ((i + 2) * (t + 2) == sum) {
                w = i;
                h = t;
                break;
            }
        }
    }

    vector<int> ret;
    ret.push_back(w + 2);
    ret.push_back(h + 2);
    return ret;
}