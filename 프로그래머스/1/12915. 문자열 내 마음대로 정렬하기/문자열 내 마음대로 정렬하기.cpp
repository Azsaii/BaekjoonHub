#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> s, int n) {
    sort(s.begin(), s.end(), [n](string a, string b) {
        if (a[n] == b[n]) return a < b;
        return a[n] < b[n];
    });
    return s;
}