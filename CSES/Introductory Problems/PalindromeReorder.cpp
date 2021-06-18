#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define MOD 1000000007LL
#define PI acos(-1)

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using max_heap = priority_queue<T>;

template <class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename... T>
void read(T &...args) {
    ((cin >> args), ...);
}

template <typename... T>
void write(T &&...args) {
    ((cout << args), ...);
}

template <typename T>
void readContainer(T &t) {
    for (auto &e : t) {
        read(e);
    }
}

template <typename T>
void writeContainer(T &t) {
    for (const auto &e : t) {
        write(e, " ");
    }
    write("\n");
}

void solve(int tc) {
    string s;
    read(s);
    vector<int> freq(26, 0);
    for (const auto &ele : s) {
        freq[ele - 'A']++;
    }
    int oddCount = 0;
    for (const auto &ele : freq) {
        if (ele % 2 == 1) {
            oddCount += 1;
        }
    }
    if (oddCount > 1) {
        write("NO SOLUTION\n");
        return;
    }
    int n = s.size();
    char ch = 'A';
    vector<char> ans(n);
    if (oddCount == 1) {
        for (int i = 0; i < 26; ++i) {
            if (freq[i] % 2 == 1) {
                freq[i]--;
                ch = (char)(i + 'A');
                break;
            }
        }
        ans[n / 2] = ch;
    }
    int i = 0, j = n - 1;
    for (int k = 0; k < 26; ++k) {
        while (freq[k] > 0) {
            ch = (char)(k + 'A');
            ans[i] = ch;
            ans[j] = ch;
            ++i;
            --j;
            freq[k] -= 2;
        }
    }
    for (const auto &ele : ans) {
        write(ele);
    }
    write("\n");
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; ++curr) {
        solve(curr);
    }
    return 0;
}