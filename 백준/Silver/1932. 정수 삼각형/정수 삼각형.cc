#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    int n, t;
    cin >> n;
    int total = n * (n + 1) / 2;
    vector<vector<int>> v(n + 1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cin >> t;
            v[i].push_back(t);
        }
    }
    for(int i = n - 1; i > 0; i--) {
        for(int j = 0; j < v[i].size() - 1; j++) {
            v[i - 1][j] += max(v[i][j], v[i][j + 1]);
        }
    }
    cout << v[0][0];
}
