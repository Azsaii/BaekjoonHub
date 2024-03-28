#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int res = 0, sum = 0;
    string s, t;
    bool ch = 0;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] - '0' >= 0) t += s[i];
        else if (s[i] == '-') {
            sum += stoi(t);
            if (!ch) { res += sum; ch = 1; }
            else res -= sum; 
            sum = 0; t = "";
        }
        else if (s[i] == '+') { sum += stoi(t); t = ""; }
    }
    sum += stoi(t);
    res = (!ch) ? sum : res - sum;
    cout << res;
    return 0;
}