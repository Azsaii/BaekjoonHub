#include <iostream>
using namespace std;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int main()
{
    init();
    int N, a = 0, b = 0, c = 0, res = 0;
    cin >> N;

    for (int i = 2; i <= N; i++) {
        int t = i;
        if (i % 5 == 0) {
            if(i % 2 == 0) while (t != 0 && t % 10 == 0) c++, t /= 10;
            if(t % 5 == 0) while (t != 0 && t % 5 == 0) b++, t /= 5;
        }
        else if (i % 2 == 0) {
            while (t != 0 && t % 2 == 0) a++, t /= 5;
        }
    }
    if (a != 0 && b != 0) res = (a <= b) ? a : b;
    cout << res + c;
    return 0;
}