#include <unistd.h>

#define ReadInt(n) { \
    char c = *p++; \
    for (; ~c & 16; c = *p++); \
    for (; c & 16; c = *p++) n = 10 * n + (c & 15); }

#define WriteInt(n) { \
    int m = n, sz = GetSize(m); \
    for (int j = sz; j --> 0; m /= 10) w[i + j] = m % 10 | 48; \
    i += sz; }

inline int GetSize(int n) {
    int ret = 1;
    for (n = n >= 0 ? n : -n; n >= 10; n /= 10) ret++;
    return ret; }

__libc_start_main() {
    char r[65536], w[2048], *p = r; syscall(0, 0, r, 65536);
    int n = 0, m = 0, mn = 1e9, i = 0; ReadInt(n); ReadInt(m);
    int imax = n - 8, jmax = m - 8;
    for (int x = 0; x <= imax; x++) {
        for (int y = 0; y <= jmax; y++) {
            int cnt = 0;
            char color = p[x * (m + 1) + y];
            for (int k = 0; k < 64; k++) {
                int i = k >> 3, j = k & 7;
                cnt += (p[(x + i) * (m + 1) + (y + j)] != color) ^ ((i + j) & 1);
            }
            mn = mn > cnt ? cnt : mn;
            mn = mn > 64 - cnt ? 64 - cnt : mn;
        }
    }
    WriteInt(mn); w[i++] = '\n';
    syscall(1, 1, w, i); _exit(0);
} main;
