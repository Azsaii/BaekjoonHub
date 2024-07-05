#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#define sz 9
using namespace std;
int n, m;
vector<int> v(sz), org;
vector<bool> ch;
void dfs(int ci){
    if(ci == m){
        for(int i = 0; i < m; i++) cout << v[i] << ' ';
        cout << '\n';
        return;
    }
    int p = 0;
    for(int i = 0; i < n; i++) {
        if (ch[i] || org[i] == p) continue;
        p = org[i];
        ch[i] = true;
        v[ci] = org[i];
        dfs(ci + 1);
        ch[i] = false;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    cin >> n >> m;
    org.resize(n);
    for(int i = 0; i < n; i++) cin >> org[i];
    sort(org.begin(), org.end());
    ch.assign(n, false);
    dfs(0);
}
