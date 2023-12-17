#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;
    vector<int> v(n);

    if (n == 0) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int limit = floor(n * 0.15 + 0.5);
    int res = 0;

    sort(v.begin(), v.end());

    for (int i = limit; i < n - limit; i++) {
        res += v[i];
    }

    int div = n - limit * 2;
    double result = static_cast<double>(res) / div;

    cout << floor(result + 0.5);
}