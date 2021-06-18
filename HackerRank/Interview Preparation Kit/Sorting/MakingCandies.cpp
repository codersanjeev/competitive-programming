#include <bits/stdc++.h>
using namespace std;

#define int __int128

__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
bool cmp(__int128 x, __int128 y) { return x > y; }

signed main() {
    int m, w, p, n;
    // cin >> m >> w >> p >> n;
    m = read();
    w = read();
    p = read();
    n = read();
    int candy = 0, invest = 0, spend = LLONG_MAX;
    while (candy < n) {
        int passes = (p - candy) / (m * w);
        if (passes <= 0) {
            int mw = (candy / p) + m + w;
            int half = ceil((mw * 1.0) / 2.0);
            if (m > w) {
                m = max(m, half);
                w = mw - m;
            } else {
                w = max(w, half);
                m = mw - w;
            }
            candy %= p;
            passes = 1;
        }
        candy += passes * m * w;
        invest += passes;
        int temp = invest + ceil((n - candy) * 1.0 / (m * w * 1.0));
        spend = min(spend, temp);
    }
    print(min(invest, spend));
    return 0;
}