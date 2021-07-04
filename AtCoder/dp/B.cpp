#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> heights(n);
    for (auto &ele : heights) cin >> ele;
    vector<int> dp(n, 1e9);
    dp[0] = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = i - k >= 0 ? i - k : 0; j < i; ++j) {
            dp[i] = min(dp[i], dp[j] + abs(heights[i] - heights[j]));
        }
    }
    cout << dp[n - 1];
    return 0;
}