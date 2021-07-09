#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;

vector<vector<int>> multiply(const vector<vector<int>> &a, const vector<vector<int>> &b) {
    int n = a.size();
    vector<vector<int>> ans(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int res = 0;
            for (int k = 0; k < n; ++k) {
                res = (res + (a[i][k] * b[k][j])) % mod;
            }
            ans[i][j] = res;
        }
    }
    return ans;
}

vector<vector<int>> binpow(const vector<vector<int>> &arr, int k) {
    if (k == 1) return arr;
    if (k % 2 == 0) {
        vector<vector<int>> temp = multiply(arr, arr);
        return binpow(temp, k / 2);
    } else {
        vector<vector<int>> temp = multiply(arr, arr);
        return multiply(binpow(temp, k / 2), arr);
    }
}

signed main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> arr(n, vector<int>(n));
    for (auto &row : arr) {
        for (auto &ele : row) cin >> ele;
    }
    arr = binpow(arr, k);
    int ans = 0;
    for (auto &row : arr) {
        for (auto &ele : row) ans = (ans + ele) % mod;
    }
    cout << ans;
    return 0;
}