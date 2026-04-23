#include <string>
#include <algorithm>

using namespace std;

string solution(string s) {
    sort(s.begin(), s.end(), [](char a, char b) {
        if (a >= 97 && b <= 90) return a > b;
        else return a > b;
    });
    return s;
}