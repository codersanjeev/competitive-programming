#include<bits/stdc++.h>
using namespace std;

char s[1024][1024], lj[5];
 
bool check(int u, int d, int l, int r) {
    for (int i = u; i <= d; ++i) {
        if (s[i][l] == 'W' || s[i][r] == 'W') {
            return true;
        }
    }
    for (int i = l; i <= r; ++i) {
        if (s[u][i] == 'W' || s[d][i] == 'W') {
            return true;
        }
    }
     return false;
}
 
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%s", lj);
            s[i][j] = lj[0];
        }
    }
    int u = 0, d = n - 1, l = 0, r = m - 1, ans = 0;
    while (u <= d && l <= r) {
        if (check(u, d, l, r)) {
            ++ans;
        }
        ++u;
        --d;
        ++l;
        --r;
    }
    printf("%d\n", ans);
    return 0;
}