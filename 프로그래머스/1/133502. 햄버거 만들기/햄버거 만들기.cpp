#include <stack>
#include <vector>

using namespace std;

int solution(vector<int> v) {
    int ret = 0;
    stack<int> s;

    for (int& i : v) {
        switch (i) {
        case 1: {
            if (s.size() >= 3 && s.top() == 3) {
                ret++;
                s.pop(); s.pop(); s.pop();
            }
            else s.push(1);
            break;
        }
        case 2: {
            if (!s.empty()) {
                if (s.top() == 1) s.push(2);
                else while(!s.empty()) s.pop();
            }
            break;
        }
        case 3: {
            if (!s.empty()) {
                if (s.top() == 2) s.push(3);
                else while (!s.empty()) s.pop();
            }
            break;
        }
        }
    }
    return ret;
}