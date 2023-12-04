#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int n, m;
    cin >> n >> m;

    int six = 1000;
    int one = 1000;

    for(int i = 0; i < m; i++){
        int t1, t2;
        cin >> t1 >> t2;
        six = t1 < six ? t1 : six;
        one = t2 < one ? t2 : one;
    }

    int r1 = n * one;
    int r2 = (n/6) * six + (n%6) * one;
    int r3 = (n/6 + 1) * six;
    cout << min({r1, r2, r3});
}