#include <unordered_set>
#include <vector>

using namespace std;

int solution(vector<int> topping) {
    size_t sz = topping.size();
    unordered_set<int> set1;
    unordered_set<int> set2;
    vector<int> sizeV1(sz);
    vector<int> sizeV2(sz);

    for (int i = 0; i < sz; i++) {
        set1.insert(topping[i]);
        sizeV1[i] = set1.size();
    }
    for (int i = sz - 1; i >= 0; i--) {
        set2.insert(topping[i]);
        sizeV2[i] = set2.size();
    }

    int ret = 0;
    for (int i = 0; i < sz - 1; i++) {
        if (sizeV1[i] == sizeV2[i + 1]) ret++;
    }
    return ret;
}