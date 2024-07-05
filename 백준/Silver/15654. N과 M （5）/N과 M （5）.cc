#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, t;
vector<int> v(8), org;
vector<bool> ch;
void dfs(int ci){
    if(ci == m){
        for(int i = 0; v[i] != 0; i++) cout << v[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = 0; i < n; i++) {
        if(ch[i]) continue;
        ch[i] = 1;
        v[ci] = org[i];
        dfs(ci + 1);
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
