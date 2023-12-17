#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0, res = 0;
    cin >> n;
    deque<int> d;
    
    for (int i = 1; i <= n; i++) {
        d.push_back(i);
    }

    while (d.size() != 1) {
        d.pop_front(); 
        if (d.size() == 1) break;
        d.push_back(d.front()); 
        d.pop_front();
    }

    cout << d.front();
    return 0;
}