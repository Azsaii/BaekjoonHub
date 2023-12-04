#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000] = { 0 };
int n, m;

int findNum(int num) {
    int s = 0;
    int e = n - 1;

    while (s <= e) {
        int avg = (s + e) / 2;
        if (arr[avg] == num) return 1;
        else if (arr[avg] < num) s = avg + 1;
        else e = avg - 1;
    }

    return 0;
}

int main(void) {
    int t;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> t;
        cout << findNum(t) << "\n";
    }
}