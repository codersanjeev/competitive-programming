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

template <typename... T>
void read(T &... args) {
    ((cin >> args), ...);
}

template <typename... T>
void write(T &&... args) {
    ((cout << args), ...);
}

void solve(int tc) {
    int k;
    string s;
    read(k, s);
    int n = s.size();
    if (n % k != 0) {
        write(-1);
        return;
    }
    unordered_map<char, int> mp;
    for (const auto &ele : s) mp[ele]++;
    for (const auto &ele : mp) {
        if (ele.second % k != 0) {
            write(-1);
            return;
        }
    }
    string ans = "";
    for (const auto &ele : mp) {
        int cnt = ele.second / k;
        string curr(cnt, ele.first);
        ans += curr;
    }
    while (k--) {
        write(ans);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; curr++) solve(curr);
    return 0;
}