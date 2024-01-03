#include <iostream>
#include <vector>
using namespace std;
#define MAX 4000000
void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int main()
{
    init();
    int N, M, K, t, start, end, mid;
    cin >> N >> M >> K;
    vector<bool> can(MAX, 0);
    vector<int> card;
    for (int i = 0; i < M; i++) {
        cin >> t;
        can[t] = 1;
    }
    for (int i = 1; i <= N; i++) {
        if (can[i]) card.push_back(i);
    }
    for (int i = 0; i < K; i++) {
        cin >> t;
        start = 0; end = card.size() - 1; mid = (start + end) / 2;
        while (start < end) {
            if (t < card[mid]) end = mid - 1;
            else if (t > card[mid]) start = mid + 1;
            else break;
            mid = (start + end) / 2;
            if (mid == 0 || mid == card.size() - 1) break;
        }
        while ((!can[card[mid]] || t >= card[mid]) && mid < card.size() - 1) mid++;
        cout << card[mid] << "\n";
        can[card[mid]] = 0;
    }
    return 0;
}