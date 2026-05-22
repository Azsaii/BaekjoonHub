#include <string>
#include <vector>

using namespace std;

int solution(vector<int> order) {
    int ret = 0;
    int sz = order.size();
    int cnt = 1;
    vector<int> stack;
    for (int i = 0; i < sz; i++) {
        if (cnt > order[i]) {
            if (stack.back() == order[i]) {
                stack.pop_back();
                ret++;
            }
            else break;
        }
        else if (cnt < order[i]) {
            while (cnt != order[i]) {
                stack.push_back(cnt++);
            }
        }
        if(cnt == order[i]) {
            cnt++;
            ret++;
        }
    }
    return ret;
}