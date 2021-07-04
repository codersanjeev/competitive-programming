#include <bits/stdc++.h>
using namespace std;

int dp[101][1001];

bool solve(int a, int b) {
    if (a == 0) return b == 0;
    if (dp[a][b] != -1) return dp[a][b] == 1;
    bool res = false;
    for (int i = 1; i <= 6; ++i) {
        res |= solve(a - 1, b - i);
    }
    return dp[a][b] = res ? 1 : 0;
}

int main() {
    int a, b;
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    cout << (solve(a, b) ? "Yes" : "No");
    return 0;
}