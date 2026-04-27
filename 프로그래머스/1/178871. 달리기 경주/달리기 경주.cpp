#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
   unordered_map<string, int> map;
    int sz = players.size();
    for (int i = 0; i < sz; i++) {
        map[players[i]] = i;
    }

    sz = callings.size();
    for (int i = 0; i < sz; i++) {
        string& s = callings[i];
        int id = map[s];
        swap(map[s], map[players[id - 1]]);
        swap(players[id], players[id - 1]);
    }
    
    return players;
}