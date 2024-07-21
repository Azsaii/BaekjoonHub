#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> v;
void fill(int a, int b) {
    v[a][b] = '*';
    v[a + 1][b - 1] = '*'; v[a + 1][b + 1] = '*';
    for (int i = b - 2; i <= b + 2; i++) v[a + 2][i] = '*';
}
void star(int a, int b, int x) {
    if (x == 3) { fill(a, b - x); return; }
    star(a, b - x / 2, x / 2);
    star(a + x / 2, b - x, x / 2);
    star(a + x / 2, b, x / 2);
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n;
    m = n * 2 - 1;
    v.resize(n, vector<char>(m, ' '));
    star(0, m, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << v[i][j];
        }
        cout << '\n';
    }
}