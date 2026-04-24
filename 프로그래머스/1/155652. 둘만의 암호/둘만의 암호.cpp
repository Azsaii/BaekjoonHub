#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    for (char& c1 : s) {
        int cnt = index;
        while (cnt--) {
            c1++;
            if (c1 == 123) c1 = 97;
            for (char& c2 : skip) {
                if (c1 == c2) cnt++;
            }
        }
    }
    return s;
}