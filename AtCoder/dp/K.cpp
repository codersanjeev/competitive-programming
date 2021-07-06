#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &ele : a) cin >> ele;
    vector<int> dp(k + 1, false);
    for (int i = 1; i <= k; ++i) {
        for (const auto &ele : a) {
            if (i - ele >= 0 && dp[i - ele] == false) {
                dp[i] = true;
                break;
            }
        }
    }
    cout << (dp[k] ? "First" : "Second");
    return 0;
}