#include <iostream>
using namespace std;
int n, m;
char v[20];
void dfs(int ci, int cur){
    if(ci >= m){
        cout << v << '\n';
        return;
    }
    for(int i = cur; i <= n; i++) {
        v[ci] = i + '0';
        v[ci + 1] = ' ';
        dfs(ci + 2, i);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    cin >> n >> m;
    m *= 2;
    dfs(0, 1);
}
