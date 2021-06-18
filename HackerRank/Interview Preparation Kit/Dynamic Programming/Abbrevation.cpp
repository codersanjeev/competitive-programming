#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>

using namespace std;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define mod 1000000007
#define PI acos(-1)

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using max_heap = priority_queue<T>;

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

// unordered_map<pair<string, string>, int, hash_pair> dp;

// bool f(string a, string b) {
//     pair<string, string> x = make_pair(a, b);
//     if (dp.find(x) != dp.end()) return dp[x];
//     if (a == "" && b == "") {
//         return dp[x] = true;
//     }
//     if (a == "") {
//         return dp[x] = false;
//     }
//     if (b == "") {
//         bool ok = true;
//         for (const auto &ch : a) ok = (ok && islower(ch));
//         return dp[x] = ok;
//     }
//     char aLast = a.back();
//     char bLast = b.back();
//     int n = a.size();
//     int m = b.size();
//     if (isupper(aLast) && isupper(bLast)) {
//         return dp[x] = (aLast == bLast && f(a.substr(0, n - 1), b.substr(0, m - 1)));
//     }
//     if (islower(aLast) && isupper(bLast)) {
//         if ((char) toupper(aLast) == bLast) {
//             return dp[x] = (f(a.substr(0, n - 1), b) || f(a.substr(0, n - 1), b.substr(0, m - 1)));
//         } else {
//             return dp[x] = f(a.substr(0, n - 1), b);
//         }
//     }
//     return dp[x] = false;
// }

void solve(int tc) {
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, true));
    for (int j = 1; j <= m; j++) dp[0][j] = false;
    for (int i = 1; i <= n; i++) dp[i][0] = dp[i - 1][0] && islower(a[i - 1]);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (islower(a[i - 1])) {
                if ((char)toupper(a[i - 1]) == b[j - 1]) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            } else {
                dp[i][j] = (a[i - 1] == b[j - 1] && dp[i - 1][j - 1]);
            }
        }
    }
    cout << (dp[n][m] ? "YES\n" : "NO\n");
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int tc = 1;
    cin >> tc;
    for (int curr = 1; curr <= tc; curr++) solve(curr);
    return 0;
}