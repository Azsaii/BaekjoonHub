#include <string>
#include <vector>

using namespace std;

string solution(vector<string> v1, vector<string> v2, vector<string> v3) {
    int sz1 = v1.size();
    int sz2 = v2.size();
    int sz3 = v3.size();
    int t1 = 0;
    int t2 = 0;
    bool check = true;

    for (int i = 0; i < sz3;) {
        if (v1[t1] == v3[i]) {
            if (t1 >= sz1) {
                check = false;
                break;
            }
            t1++;
            i++;
            continue;
        }
        else if (v2[t2] == v3[i]) {
            if (t2 >= sz2) {
                check = false;
                break;
            }
            t2++;
            i++;
            continue;
        }
        else {
            check = false;
            break;
        }
    }

    if (check == true) return "Yes";
    else return "No";
}