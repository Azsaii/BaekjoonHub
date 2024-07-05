#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define sz 9
using namespace std;
int n, m, t;
vector<int> v(sz), org;
void dfs(int ci){
    if(ci == m){
        for(int i = 0; i < m; i++) cout << v[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = 0; i < org.size(); i++) {
        if(ci != 0 && v[ci - 1] > org[i]) continue;
        v[ci] = org[i];
        dfs(ci + 1);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    cin >> n >> m;
    map<int, int> map;
    for(int i = 0; i < n; i++) {
        cin >> t;
        map[t]++;
    }
    for(auto m : map) org.push_back(m.first);
    dfs(0);
}
