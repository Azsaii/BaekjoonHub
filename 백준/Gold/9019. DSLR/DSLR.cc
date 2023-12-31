#include <iostream>
#include <queue>
#include <string>
using namespace std;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

string name[4] = { "D", "S", "L", "R"};
int calc(int n, int mode) {
    switch (mode) {
    case 0: return (n * 2) % 10000;
    case 1: return (n + 9999) % 10000;
    case 2: return (n % 1000) * 10 + n / 1000;
    case 3: return n / 10 + (n % 10) * 1000;
    }
}

int main()
{
    init();
    int T, a, b;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> a >> b;
        queue<pair<string, int>> q;
        vector<int> visited(10000, 0);
        string str;
        visited[a] = 1;
        q.push({str, a});
        while (!q.empty()) {
            string op = q.front().first;
            int node = q.front().second;
            q.pop();

            if (node == b) {
                cout << op << "\n";
                break;
            }

            for (int j = 0; j < 4; j++) {
                int x = calc(node, j);
                if (visited[x]) continue;
                visited[x] = 1;
                q.push(make_pair(op + name[j], x));
            }
        }
    }
    return 0;
}