#include <iostream>
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
        int N;
        uint64_t M, sum = 0, min, max = 0, start = 1, end, mid;
        uint64_t arr[100];
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            if (i == 0 || min > arr[i]) min = arr[i];
            if (max < arr[i]) max = arr[i];
        }
        for (int i = 0; i < N; i++) sum += arr[i] / min;
        mid = sum * min / M;
        if (mid == 0) mid++;
        end = max;
        while (start <= end) { 
            sum = 0;
            for (int i = 0; i < N; i++) sum += arr[i] / mid;
            if (sum < M) end = mid - 1;
            else start = mid + 1;
            mid = (start + end) / 2;
        }
        cout << "#" << tc << " " << end << "\n";
    }
    return 0;
}