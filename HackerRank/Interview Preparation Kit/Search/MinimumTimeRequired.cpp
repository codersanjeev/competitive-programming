#include <bits/stdc++.h>
using namespace std;

#define int long long

bool canMake(vector<int> &arr, int days, int X) {
    int curr = 0;
    for (const auto &ele : arr) {
        curr += (days / ele);
    }
    return curr >= X;
}

signed main() {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (auto &ele : arr) {
        cin >> ele;
    }
    int L = 0, H = *max_element(arr.begin(), arr.end()) * x, ans = 0;
    while (L <= H) {
        int M = L + (H - L) / 2;
        if (canMake(arr, M, x)) {
            ans = M;
            H = M - 1;
        } else {
            L = M + 1;
        }
    }
    cout << ans;
    return 0;
}