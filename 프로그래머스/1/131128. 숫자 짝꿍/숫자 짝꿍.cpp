#include <string>
#include <vector>

using namespace std;

string solution(string x, string y) {
    string ret = "";
    vector<int> v1(10);
    vector<int> v2(10);

    int xlen = x.length();
    int ylen = y.length();

    for (int i = 0; i < xlen; i++) v1[x[i] - 48]++;
    for (int i = 0; i < ylen; i++) v2[y[i] - 48]++;
    for (int i = 9; i >= 0; i--) {
        int t = v1[i] < v2[i] ? v1[i] : v2[i];
        while (t--) {
            ret += i + 48;
        }
    }
    if (ret.size() == 0) ret = "-1";
    else if (ret[0] == '0') ret = "0";
    return ret;
}