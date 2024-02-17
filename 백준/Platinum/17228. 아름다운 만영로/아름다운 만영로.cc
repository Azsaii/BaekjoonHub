#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define IDX(v, x) lower_bound(all(v), x) - v.begin()
using namespace std;

using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
using Edge = pair<int, char>;

constexpr ll p1 = 917, m1 = 998244353;

int N, ans;
vector<Edge> G[505050];
string P; ll ph, pw = 1;

vector<ll> stk;

void DFS(int v){
    if(stk.size() > P.size()){
        ll now = stk.back() - stk[stk.size()-P.size()-1] * pw;
        now %= m1; if(now < 0) now += m1;
        if(ph == now) ans++;
    }
    for(const auto &i : G[v]){
        stk.push_back((stk.back() * p1 + i.y) % m1);
        DFS(i.x);
        stk.pop_back();
    }
}

int main(){
    cin >> N;
    for(int i=1; i<N; i++){
        int s, e; char x; cin >> s >> e >> x;
        G[s].emplace_back(e, x);
    }
    cin >> P;
    for(const auto &c : P){
        ph = (ph * p1 + c) % m1;
        pw = pw * p1 % m1;
    }
    stk.push_back(0);
    DFS(1);
    cout << ans;
}