#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    int sz = s.length();
    vector<int> v(sz, -1);
    vector<vector<int>> index(26);

    for (int i = 0; i < sz; i++) {
        int ind = s[i] - 97;
        index[ind].push_back(i);
    }

    for (int i = 0; i < sz; i++) {
        int ind = s[i] - 97;
        int tsz = index[ind].size();
        for (int k = 0; k < tsz; k++) {
            int val = index[ind][k];
            if (val < i) v[i] = i - val;
            else break;
        }
    }
    
    return v;
}