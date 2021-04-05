#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("trapv")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define mod 1000000007
#define PI acos(-1)

// C(n, r) = n! / (r! * (n - r)!)
// C(n, r) = C(n, n - r)
// C(n, r) = C(n - 1, r - 1) + C(n - 1, r)
int nCr(int n, int r) {
    long double res = 1;
    r = min(r, n - r);
    for (int i = 1; i <= r; i++) {
        res = res * (n - r + i) / i;
    }
    return (int)(res + 0.01);
}

// (x ^ y) % mod
int modpow(int x, int y, int m) {
    x %= m;
    int res = 1LL;
    while (y > 0) {
        if (y & 1) {
            res = (res * x) % m;
        }
        x = (x * x) % m;
        y >>= 1;
    }
    return res;
}

bool isValid(vector<vector<char>> &arr, vector<int> x, vector<int> y, int n, int m) {
    return x[0] < n && x[1] < n && x[2] < n && x[0] >= 0 && x[1] >= 0 && x[2] >= 0 && y[0] < m && y[1] < m && y[2] < m && y[0] >= 0 && y[1] >= 0 && y[2] >= 0 && arr[x[0]][y[0]] == 'a' && arr[x[1]][y[1]] == 'b' && arr[x[2]][y[2]] == 'a';
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 's') {
                if (isValid(arr, vector<int>{i + 1, i + 2, i + 3}, vector<int>{j + 1, j + 2, j + 3}, n, m)) {
                    ans++;
                }
                if (isValid(arr, vector<int>{i - 1, i - 2, i - 3}, vector<int>{j + 1, j + 2, j + 3}, n, m)) {
                    ans++;
                }
                if (isValid(arr, vector<int>{i, i, i}, vector<int>{j + 1, j + 2, j + 3}, n, m)) {
                    ans++;
                }
                if (isValid(arr, vector<int>{i + 1, i + 2, i + 3}, vector<int>{j, j, j}, n, m)) {
                    ans++;
                }
            }
        }
    }
    cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}