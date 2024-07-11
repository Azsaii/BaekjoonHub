#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    int n, a, b;
    cin >> n;
    vector<vector<int>> v(n + 1);
    vector<bool> vst(n + 1, 0);
    vector<int> res(n + 1);
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<int > q;
    q.push(1);
    vst[1] = 1;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        for(int t : v[top]){
            if(vst[t] == 0) {
                vst[t] = 1;
                res[t] = top;
                q.push(t);
            }
        }
    }
    for(int i = 2; i <= n; i++) cout << res[i] << '\n';
}
