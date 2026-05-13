#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> nums) {
    size_t sz = nums.size();
    vector<int> ret(sz, -1);
    for (int i = sz - 2; i >= 0; i--) {
        for (int k = i + 1; k < sz; k++) {
            if (nums[i] < nums[k]) {
                ret[i] = nums[k];
                break;
            }
            else {
                if (ret[k] == -1) {
                    ret[i] = -1;
                    break;
                }
                else if (nums[i] < ret[k]) {
                    ret[i] = ret[k];
                    break;
                }
            }
        }
    }
    return ret;
}