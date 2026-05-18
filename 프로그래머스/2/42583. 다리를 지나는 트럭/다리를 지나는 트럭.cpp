#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int ret = 0;
    int currentWeight = 0;
    int index = 0;
    int compIndex = -1;
    int sz = truck_weights.size();
    vector<int> timeCheck(sz, 0);
    while (1) {
        ret++;

        int lim = index;
        if (index >= sz) lim = sz;
        for (int i = compIndex + 1; i < lim; i++) {
            if (++timeCheck[i] == bridge_length) {
                compIndex++;
                currentWeight -= truck_weights[i];
            }
        }

        if (index < sz && currentWeight + truck_weights[index] <= weight) {
            currentWeight += truck_weights[index++];
        }	

        if (compIndex == sz - 1) break;
    }
    return ret;
}