#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> v;
void dfs(int cur){
    if(v.size() == m){
        for(int i : v) cout << i << ' ';
        cout << '\n';
        return;
    }
    for(int i = cur + 1; i <= n; i++) {
        v.push_back(i);
        dfs(cur + 1);
        v.pop_back();
        cur++;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    cin >> n >> m;
    dfs(0);
}
