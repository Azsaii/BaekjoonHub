#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> l, vector<int> v) {
    int ret = n;
    vector<int> tmp(n + 1, 1);
    for (int& i : l) tmp[i] = 0;
    for (int& i : v) tmp[i]++;
    for (int i = 1; i <= n; i++) {
        if (tmp[i] == 0) {
            if (tmp[i - 1] == 2) {
                tmp[i]++;
                tmp[i - 1]--;
            }
            else if (tmp[i + 1] == 2) {
                tmp[i]++;
                tmp[i + 1]--;
            }
            else ret--;
        }
    }
    return ret;
}