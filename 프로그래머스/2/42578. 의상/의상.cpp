#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int ret = 1;
    unordered_map<string, int> map;
    for (const auto& cv : clothes) {
        map[cv[1]]++;
    }
    for (const auto& i : map) {
        ret *= (i.second + 1);
    }
    return ret - 1;
}