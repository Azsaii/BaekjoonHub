#include <iostream>
#include <set>
using namespace std;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int main()
{
    init();
    int N, M, t, L=0,R=0;
    char c;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> M;
        multiset<int> ms;
        for (int k = 0; k < M; k++) {
            cin >> c >> t;
            if (c == 'I') ms.insert(t);
            else if (c == 'D') {
                if (ms.size() == 0) continue;
                if(t == -1) ms.erase(ms.begin());
                else if(t == 1) ms.erase(--ms.end());
            }
        }
        if (ms.size() == 0) cout << "EMPTY\n";
        else cout << *ms.rbegin() << " " << *ms.begin() << "\n";
    }

    return 0;
}