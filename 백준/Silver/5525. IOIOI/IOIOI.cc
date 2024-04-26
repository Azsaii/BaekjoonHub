#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int N, M;
    char c;
    cin >> N >> M;
    int tarlen = 2 * N + 1, res = 0, cnt = 0;
    bool check = 0;
    for (int i = 0; i < M; i++) {
        cin >> c;
        //cout << "c: " << c << ", cnt: " << cnt << ", res: " << res << '\n';       
        if (check == 1 && c == 'O') { cnt = N * 2; check = 0; continue; }
        check = 0;
        if (cnt % 2 == 0 && c == 'I') cnt++;
        else if (cnt % 2 == 1 && c == 'O') cnt++;
        else if (cnt % 2 == 1 && c == 'I') cnt = 1;
        else cnt = 0;
        if (cnt == tarlen) { res++; cnt = 0; check = 1; }
    }
    cout << res << '\n';
}