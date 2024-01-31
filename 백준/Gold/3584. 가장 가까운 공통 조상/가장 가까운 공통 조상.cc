#include <iostream>
#include <vector>
#include <set>
using namespace std;
void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}
int findParent(const vector<int> pv, int n1, int n2) {
    set<int> ps;
    ps.insert(n1);
    while (pv[n1] != -1) {
        ps.insert(pv[n1]);
        n1 = pv[n1];
    }
    if (ps.count(n2)) return n2;
    while (pv[n2] != -1) {
        if (ps.count(pv[n2]))
            return pv[n2];
        n2 = pv[n2];
    }
    return 0;
}
int main()
{
    init();
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int N, p, c;
        cin >> N;
        vector<int> pv(N + 1, -1);
        for (int i = 0; i < N - 1; i++) {
            cin >> p >> c;
            pv[c] = p;
        }
        cin >> p >> c;
        int parent = findParent(pv, p, c);
        cout << parent << "\n";
    }
    return 0;
}