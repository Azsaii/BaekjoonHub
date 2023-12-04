#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b){
    return a.second < b.second;
}

void sort(map<string, int>& map) {
    vector<pair<string,int>> vec;
    for(auto& it : map){
        vec.push_back(it);
    }
    stable_sort(vec.begin(), vec.end(), cmp);

    for(auto& it : vec){
        cout << it.first << endl;
    }
}

int main(void){
    int n;
    string s;
    cin >> n;

    map<string, int> map;
    while(n--){
        cin >> s;
        map.insert(pair<string, int>(s, s.length()));
    }
    
    sort(map);
}