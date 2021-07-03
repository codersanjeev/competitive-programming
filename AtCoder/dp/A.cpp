#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for (auto &ele : heights) cin >> ele;
    int x = 0, y = abs(heights[1] - heights[0]);
    // vector<int> dp(n, 0);
    // dp[1] = abs(heights[1] - heights[0]);
    for (int i = 2; i < n; ++i) {
        int a = x + abs(heights[i] - heights[i - 2]);
        int b = y + abs(heights[i] - heights[i - 1]);
        x = y;
        y = min(a, b);
        // dp[i] = min(dp[i - 1] + abs(heights[i] - heights[i - 1]), dp[i - 2] + abs(heights[i] - heights[i - 2]));
    }
    // cout << dp[n - 1];
    cout << y;
    return 0;
}