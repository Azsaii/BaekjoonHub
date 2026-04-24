#include <string>
#include <vector>

using namespace std;

int solution(vector<string> v) {
    int ret = 0;
    int sz = v.size();
    for (int i = 0; i < sz; i++) {
        int len = v[i].length();
        string prev = "";
        bool ch = true;
        for (int k = 0; k < len;) {
            if (k + 3 <= len) {
                string sub = v[i].substr(k, 3);
                if (prev == sub);
                else if (sub == "aya" || sub == "woo") {
                    k += 3;
                    prev = sub;
                    continue;
                }
            }

            if (k + 2 <= len) {
                string sub = v[i].substr(k, 2);
                if (prev == sub);
                else if (sub == "ye" || sub == "ma") {
                    k += 2;
                    prev = sub;
                    continue;
                }
            }

            ch = false;
            break;
        }

        if (ch == true) ret++;
    }
    return ret;
}