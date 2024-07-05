#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;
int n, m;
vector<int> v, org;
vector<bool> ch;
unordered_set<string> used_sequences;
void dfs(int ci){
    if(ci == m){
        for(int i = 0; i < m; i++) cout << v[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = 0; i < n; i++) {
        if (ch[i]) continue;
        v[ci] = org[i];
        string sequence;
        for (int j = 0; j <= ci; j++) sequence += to_string(v[j]) + ",";
        if (used_sequences.find(sequence) != used_sequences.end()) continue;
        used_sequences.insert(sequence);
        ch[i] = true;
        dfs(ci + 1);
        ch[i] = false;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    cin >> n >> m;
    org.resize(n);
    v.resize(m);
    for(int i = 0; i < n; i++) cin >> org[i];
    sort(org.begin(), org.end());
    ch.assign(n, false);
    dfs(0);
}
