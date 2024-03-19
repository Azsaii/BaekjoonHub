#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    unordered_map<string, string> m;
    string a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        m[a] = b;
    }
    for (int i = 0; i < M; i++) { cin >> a; cout << m[a] << '\n'; }
    return 0;
}