#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a, b;
    cin >> a >> b;
    int res = 1;
    while (b > a) {
        res++;
        if (b % 2 == 0) {
            b /= 2;
        } else if (b % 10 == 1) {
            b /= 10;
        } else {
            cout << "-1";
            return 0;
        }
    }
    
    cout << (b == a ? res : -1);
    return 0;
}