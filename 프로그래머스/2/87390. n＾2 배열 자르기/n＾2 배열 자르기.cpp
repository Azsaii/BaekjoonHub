#include <vector>
#define ll long long

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> ret;
    for (ll i = left; i <= right; i++) {
        int row = i / n;
        int col = i % n;
        ret.push_back((row > col ? row : col) + 1);
    }
    return ret;
}