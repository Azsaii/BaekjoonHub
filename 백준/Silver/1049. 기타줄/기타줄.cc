#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int n, m, t1, t2, a=1000, b=1000;
    cin >> n >> m;

    while(m--){
        cin >> t1 >> t2;
        a = min({a, t1});
        b = min({b, t2});
    }

    cout << min({n * b, (n/6) * a + (n%6) * b, (n/6 + 1) * a});
}