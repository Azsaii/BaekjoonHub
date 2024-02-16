#include<bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T, k;
    string str;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cin >> k >> str;
        if (k > str.size()) {
            cout << "none\n";
            continue;
        }
        vector<int> alp(27, 0), use;
        for (int i = 0; i < str.size(); i++) {
            alp[str[i] - 'a'] += 1;
        }
        for (int i = 0; i < 27; i++) {
            int cnt = alp[i];
            while (cnt != 0) {
                use.emplace_back(i);
                cnt--;
            }
        }
        int tcnt = 0;
        for (int i = 0; i < k; i++) {
            if (use[i] == use[k - 1]) tcnt++;
        }
        // tcnt -> target문자를 시작으로하는 문자열 중 가장큰것
        tcnt--;
        string s;
        vector<string> ress;
        for (int i = 0; i < str.size(); i++) {
            if (s.size() == 0 && str[i] - 'a' == use[k - 1]) {
                s = str.substr(i);
                ress.push_back(s);
            }
            else if (str[i] - 'a' == use[k - 1]) {
                ress.push_back(str.substr(i));
            }
        }
        sort(ress.begin(), ress.end());
        cout << "#" << tc << ' ' << ress[tcnt] << '\n';
    }
    return 0;
}