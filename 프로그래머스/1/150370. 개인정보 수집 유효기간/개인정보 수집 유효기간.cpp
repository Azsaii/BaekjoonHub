#include <string>
#include <vector>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> v;

    int tyear = (today[2] - 48) * 10 + (today[3] - 48);
    int tmon = (today[5] - 48) * 10 + (today[6] - 48);
    int tday = (today[8] - 48) * 10 + (today[9] - 48);
    int tsum = tyear * 336 + tmon * 28 + tday;

    int sz = terms.size();
    vector<int> termv(26);
    for (int i = 0; i < sz; i++) {
        int len = terms[i].length();
        int g = len - 2;
        int sum = 0;
        int index = len - 1;
        int t = 1;
        while (g--) {
            sum += (terms[i][index--] - 48) * t;
            t *= 10;
        }

        termv[terms[i][0] - 65] = sum;
    }

    sz = privacies.size();
    for (int i = 0; i < sz; i++) {
        string& s = privacies[i];
        int year = (s[2] - 48) * 10 + (s[3] - 48);
        int mon = (s[5] - 48) * 10 + (s[6] - 48);
        int day = (s[8] - 48) * 10 + (s[9] - 48);
        int sum = year * 336 + mon * 28 + day;
        char c = s[11];

        int gap = (tsum - sum) / 28;
        if (gap >= termv[c - 65]) v.push_back(i + 1);
    }
    return v;
}