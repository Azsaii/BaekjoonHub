#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int T, M, N, t;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        int res = 0, mii = 0;
        cin >> N >> M;
        deque<pii> orig, v;
        vector<int> maxsort(N);
        for (int i = 0; i < N; i++) { 
            cin >> t; 
            orig.push_back({ t, i });
            maxsort[i] = t;
        }
        if (N == 1) { cout << "1\n"; continue; }
        pii target = orig[M];
        sort(maxsort.rbegin(), maxsort.rend());
        while (mii < N) {    
            while (orig.front().first != maxsort[mii]) {
                pii f = orig.front();
                orig.pop_front();
                orig.push_back(f);
            }
            if (orig[0] == target && maxsort[mii] == target.first) break;
            res++; mii++;
            orig.pop_front();
        }
        cout << res + 1 << '\n';
    }
    return 0;
}