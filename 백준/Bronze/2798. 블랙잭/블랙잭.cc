#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int n, m, res = 0, tmp = 0;
    int arr[100];
    int cnt = 0;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    
    int end = n - 1;
    int endg1 = n - 2;
    int endg2 = n - 3;

    while (1) {
        tmp = arr[end] + arr[endg1] + arr[endg2];
        
        if (tmp <= m) {
            res = tmp > res ? tmp : res;
        }

        if (end < 2) break;
        else if (endg2 == 0 && endg1 != 1) {
            endg1--;
            endg2 = endg1 - 1;
        }
        else if (endg2 == 0 && endg1 == 1) {
            end--;
            endg1 = end - 1;
            endg2 = endg1 - 1;
        }
        else endg2--;
    }

    cout << res;
}