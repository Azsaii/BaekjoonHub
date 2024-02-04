#include <iostream>
#include <cmath>
using namespace std;
void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}
int main() {
    init();
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        uint64_t N;
        cin >> N;
        int64_t t = floor(sqrt(N * 2));
        if ((t * (t + 1)) / 2 != N) t = -1;
        cout << "#" << tc << " " << t << "\n";
    }
    return 0;
}
