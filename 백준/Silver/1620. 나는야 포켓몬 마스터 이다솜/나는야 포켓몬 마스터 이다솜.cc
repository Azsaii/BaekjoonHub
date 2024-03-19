#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    unordered_map<string, int> m1;
    unordered_map<int, string> m2;
    string a;
    for (int i = 1; i <= N; i++) {
        cin >> a;
        m1[a] = i;
        m2[i] = a;
    }
    for (int i = 0; i < M; i++) { 
        cin >> a;
        if (a[0] - '0' >= 10) cout << m1[a] << '\n';
        else cout << m2[stoi(a)] << '\n';
    }
    return 0;
}