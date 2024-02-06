#include <iostream>
#include <vector>
#include <map>
using namespace std;
int lis[100], idx[100], v[100];
map<int, int> m;
void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}
int main() {
    init();
    int N, cnt = 0, a, b, index = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        m[a] = b;
    }
    auto it = m.begin();
    lis[0] = v[0] = it->second;
    for (auto iter : m) {
        int val = iter.second;
        v[index] = val;
        if (lis[cnt] < val) {
            lis[++cnt] = val;
            idx[index] = cnt;
        }
        else {
            int s = 0, e = cnt;
            while (s < e) {
                int mid = (s + e) / 2;
                if (lis[mid] >= val) e = mid;
                else s = mid + 1;
            }
            lis[e] = val;
            idx[index] = e;
        }
        index++;
    }
    cout << N - ++cnt;
    return 0;
}