#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string s) {
    int ret = 0;
    int sz = s.length();
    vector<int> v;

    for (int i = 0; i < sz;) {
        bool check = false;

        if (s[i] >= 48 && s[i] <= 57) {
            v.push_back(s[i] - 48);
            i++;
            continue;
        }

        if (i + 2 <= sz) {
            string ts = s.substr(i, 3);
            if (ts == "one") {
                v.push_back(1);
                check = true;
            }
            else if (ts == "two") {
                v.push_back(2);
                check = true;
            }
            else if (ts == "six") {
                v.push_back(6);
                check = true;
            }

            if (check == true) {
                i += 3;
                continue;
            }
        }

        if (i + 3 <= sz) {
            string ts = s.substr(i, 4);
            if (ts == "zero") {
                v.push_back(0);
                check = true;
            }
            else if (ts == "four") {
                v.push_back(4);
                check = true;
            }
            else if (ts == "five") {
                v.push_back(5);
                check = true;
            }
            else if (ts == "nine") {
                v.push_back(9);
                check = true;
            }

            if (check == true) {
                i += 4;
                continue;
            }
        }

        if (i + 4 <= sz) {
            string ts = s.substr(i, 5);
            if (ts == "three") {
                v.push_back(3);
                check = true;
            }
            else if (ts == "seven") {
                v.push_back(7);
                check = true;
            }
            else if (ts == "eight") {
                v.push_back(8);
                check = true;
            }

            if (check == true) {
                i += 5;
                continue;
            }
        }

        i++;
    }

    sz = v.size();
    int p = sz;
    for (int i = 0; i < sz; i++) {
        ret += v[i] * pow(10, --p);
    }

    return ret;
}