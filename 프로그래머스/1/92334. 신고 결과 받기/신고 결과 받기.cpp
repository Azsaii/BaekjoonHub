#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    int sz = id_list.size();
    vector<int> ret(sz);
    vector<unordered_set<int>> repo(sz);
    unordered_map<string, int> map;

    for (int i = 0; i < sz; i++) {
        string& s = id_list[i];
        map[s] = i;
    }

    sz = report.size();
    for (string& s : report) {
        int emp = s.find(" ");
        int len = s.length();
        string s1 = s.substr(0, emp);
        string s2 = s.substr(emp + 1, len - emp - 1);


        repo[map[s2]].insert(map[s1]);
    }

    for (const unordered_set<int> & us : repo) {
        sz = us.size();
        if (sz >= k) {
            for (const int& i : us) {
                ret[i]++;
            }
        }
    }
    return ret;
}