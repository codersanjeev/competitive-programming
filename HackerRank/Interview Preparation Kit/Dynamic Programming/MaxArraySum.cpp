#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr) {
    int n = arr.size();
    vector<int> dp(n, 0);
    dp[0] = max(0, arr[0]);
    dp[1] = max(dp[0], arr[1]);
    for (int i = 2; i < n; i++) {
        dp[i] = max({dp[i - 1], dp[i - 2], dp[i - 2] + arr[i]});
    }
    return dp[n - 1];
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &ele : arr) {
        cin >> ele;
    }
    cout << solve(arr);
    return 0;
}