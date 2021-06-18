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
    read(n);
    vector<int> a(n);
    readContainer(a);
    int mx = LLONG_MIN, ans = 2;
    int m = *max_element(a.begin(), a.end());
    for (int i = 2; i <= m; i++) {
        int cnt = 0;
        for (const auto &ele : a) {
            if (ele % i == 0) cnt++;
        }
        if (mx < cnt) {
            mx = cnt;
            ans = i;
        }
    }
    write(ans);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; curr++) solve(curr);
    return 0;
}