#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> v) {
    size_t len = v.size();
    unordered_set<int> set;
    for (int i = 1; i <= len; i++) {
        for (int k = 0; k < len; k++) {
            int sum = 0;
            for (int j = 0; j < i; j++) {
                int ind = k + j;
                if (ind >= len) ind -= len;
                sum += v[ind];
            }

            set.insert(sum);

            if (i == len) break;
        }
    }
    return set.size();
}