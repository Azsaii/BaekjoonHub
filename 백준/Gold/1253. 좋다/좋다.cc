#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> v;
unordered_map<int, int> m;
int f(int i, int j, int t) {
    int gap = v[i] - v[j];
    if(gap == v[i] && gap == v[j]) {
        if(m[gap] >= 3) return t + 1;
        else return t;
    }
    else if(gap == v[i] || gap == v[j]) {
        if(m[gap] >= 2) return t + 1;
        else return t;
    }
    else  {
        if(m.find(gap) != m.end()) return t + 1;
        else return t;
    }
    return t;
}
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    int n, t;
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> t;
        v[i] = t;
        m[t]++;
    }
    sort(v.begin(), v.end());
    t = 0;
    for(int i = 0; i < n; i++) {
        if(v[i] >= 0) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                int r = f(i, j, t);
                if(r != t) {t = r; break;}
            }
        }
        else {
            for(int j = n - 1; j >= 0; j--) {
                if(i == j) continue;
                int r = f(i, j, t);
                if(r != t) {t = r; break;}
            }
        }
    }
    cout << t;
}
