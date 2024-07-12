#include <cstdio>
#include <vector>
using namespace std;
char rbuf[1<<17];
int idx, ridx;
inline char read() {
    if (idx == ridx) {
        ridx = fread(rbuf, 1, 1<<17, stdin);
        if (!ridx) return 0;
        idx = 0;
    }
    return rbuf[idx++];
}
inline int readInt() {
    int sum = 0;
    char now = read();
    
    while (now <= 32) now = read();
    while (now >= 48) sum = sum * 10 + now - '0', now = read();
    
    return sum;
}
int main() {
    int n = readInt();
    vector<int> v[501];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int t = readInt();
            v[i].push_back(t);
        }
    }
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < v[i].size() - 1; j++)
            v[i - 1][j] += max(v[i][j], v[i][j + 1]);
    }
    printf("%d", v[0][0]);
    return 0;
}
