#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ele, x = 0, y = 0, z = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ele;
        if (ele == 1)
            ++x;
        else if (ele == 2)
            ++y;
        else
            ++z;
    }
    double dp[301][301][301];
    memset(dp, 0, sizeof(dp));
    for (int three = 0; three <= n; three++) {
        for (int two = 0; two <= n; two++) {
            for (int one = 0; one <= n; one++) {
                int zero = n - three - two - one;
                if (zero == n || one + two + three > n)
                    continue;
                double ans = 1;
                //choose 3 sushi
                if (three > 0)
                    ans += (1.0 * three / n) * dp[three - 1][two + 1][one];
                //choose 2 sushi
                if (two > 0)
                    ans += (1.0 * two / n) * dp[three][two - 1][one + 1];
                //choose 1 sushi
                if (one > 0)
                    ans += (1.0 * one / n) * dp[three][two][one - 1];
                dp[three][two][one] = ans / (1 - 1.0 * zero / n);
            }
        }
    }
    cout << fixed << setprecision(16) << dp[z][y][x];
    return 0;
}