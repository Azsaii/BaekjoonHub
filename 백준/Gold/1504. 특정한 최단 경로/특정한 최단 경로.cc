#include <bits/stdc++.h>
#define ll long long
#define pli pair<ll, int>
using namespace std;
// https://github.com/csehydrogen/algorithm/blob/master/fast_io.cc
class FastIO {
    int fd, bufsz;
    char* buf, * cur, * end;
public:
    FastIO(int _fd = 0, int _bufsz = 1 << 20) : fd(_fd), bufsz(_bufsz) {
        buf = cur = end = new char[bufsz];
    }
    ~FastIO() {
        delete[] buf;
    }
    bool readbuf() {
        cur = buf;
        end = buf + bufsz;
        while (true) {
            size_t res = fread(cur, sizeof(char), end - cur, stdin);
            if (res == 0) break;
            cur += res;
        }
        end = cur;
        cur = buf;
        return buf != end;
    }
    int readint() {
        while (true) {
            if (cur == end) readbuf();
            if (isdigit(*cur) || *cur == '-') break;
            ++cur;
        }
        bool sign = true;
        if (*cur == '-') {
            sign = false;
            ++cur;
        }
        int ret = 0;
        while (true) {
            if (cur == end && !readbuf()) break;
            if (!isdigit(*cur)) break;
            ret = ret * 10 + (*cur - '0');
            ++cur;
        }
        return sign ? ret : -ret;
    }
};
FastIO fio;
int n;
vector<vector<ll>> v;
vector<ll> dst;
void dij(int x) {
    dst.assign(n + 1, INT32_MAX);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    dst[x] = 0;
    pq.push({ 0, x });
    while (!pq.empty()) {
        auto [cv, cn] = pq.top();
        pq.pop();
        if (cv > dst[cn]) continue;
        for (int i = 1; i <= n; i++) {
            ll nv = cv + v[cn][i];
            if (dst[i] > nv) {
                dst[i] = nv;
                pq.push({ nv, i });
            }
        }
    }
}
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int e, a, b, c, v1, v2; n = fio.readint(); e = fio.readint();
    v.assign(n + 1, vector<ll>(n + 1, INT32_MAX));
    dst.resize(n + 1);
    for (int i = 0; i < e; i++) {
        a = fio.readint(); b = fio.readint(); c = fio.readint();
        v[a][b] = c; v[b][a] = c;
        v[a][a] = 0; v[b][b] = 0;
    }
    v1 = fio.readint(); v2 = fio.readint();
    dij(v1);
    ll r1 = dst[1] + dst[v2];
    ll r2 = dst[n];
    if (r1 >= INT32_MAX && r2 >= INT32_MAX) { cout << -1; return 0; }
    dij(v2);
    r1 += dst[n];
    r2 += dst[1] + dst[v1];
    if (r1 >= INT32_MAX && r2 >= INT32_MAX) { cout << -1; return 0; }
    cout << min(r1, r2);
}