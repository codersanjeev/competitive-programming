#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &ele : arr) cin >> ele;
    int sum = accumulate(cbegin(arr), cend(arr), 0), ans = sum;
    vector<bool> dp(sum + 1, false);
    dp[0] = true;
    for (int i = 0; i < n; ++i) {
        for (int rem = sum - arr[i]; rem >= 0; --rem) {
            if (dp[rem] == true) {
                dp[rem + arr[i]] = true;
            }
        }
    }
    for (int i = 1; i <= sum; ++i) {
        if (dp[i] == true) {
            ans = min(ans, max(i, sum - i));
        }
    }
    cout << ans;
    return 0;
}