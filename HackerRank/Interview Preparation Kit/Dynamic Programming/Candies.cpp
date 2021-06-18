#include <bits/stdc++.h>
using namespace std;

#define int long long

int solve(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n);
    ans[0] = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            ans[i] = ans[i - 1] + 1;
        } else {
            ans[i] = 1;
        }
    }
    int cnt = ans[n - 1], curr = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > arr[i + 1]) {
            curr = ans[i + 1] + 1;
        } else {
            curr = 1;
        }
        cnt += max(curr, ans[i]);
        ans[i] = curr;
    }
    return cnt;
}

signed main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &ele : arr) {
        cin >> ele;
    }
    cout << solve(arr);
    return 0;
}