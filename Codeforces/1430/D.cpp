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

template <typename T>
void readContainer(T &t) {
    for (auto &e : t) read(e);
}

template <typename T>
void writeContainer(T &t) {
    for (const auto &e : t) write(e, " ");
    write("\n");
}

void solve(int tc) {
    int n;
    string s;
    read(n, s);
    vector<int> segs;
    int j = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[j]) {
            segs.push_back(i - j);
            j = i;
        }
    }
    segs.push_back(n - j);
    n = segs.size();
    j = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        while (j < n) {
            if (segs[j] > 1) {
                --segs[j];
                break;
            }
            ++j;
        }
        if (j == n) ++i;
        while (j <= i) {
            j++;
        }
        ++ans;
    }
    write(ans, "\n");
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    read(tc);
    for (int curr = 1; curr <= tc; curr++) solve(curr);
    return 0;
}