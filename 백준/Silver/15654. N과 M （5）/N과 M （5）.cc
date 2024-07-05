#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, t;
vector<int> v, org;
vector<bool> ch;
void dfs(int ci){
    if(v.size() == m){
        for(int i : v) cout << i << ' ';
        cout << '\n';
        return;
    }
    for(int i = 0; i < n; i++) {
        if(ch[i]) continue;
        ch[i] = 1;
        v.push_back(org[i]);
        dfs(ci + 1);
        v.pop_back();
        ch[i] = 0;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> t;
        org.push_back(t);
    }
    sort(org.begin(), org.end());
    ch.assign(n, 0);
    dfs(0);
}
