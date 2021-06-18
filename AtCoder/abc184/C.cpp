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
    int a, b, c, d;
    read(a, b, c, d);
    if (a == c && b == d) {
        write(0);
    } else if (((a + b) == (c + d)) || ((a - b) == (c - d)) || abs(a - c) + abs(b - d) <= 3) {
        write(1);
    } else if ((abs(a - c) + abs(b - d)) <= 6 || (abs((a + b) - (c + d)) <= 3) || (abs((a - b) - (c - d)) <= 3) || (a + b) % 2 == (c + d) % 2) {
        write(2);
    } else {
        write(3);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; curr++) solve(curr);
    return 0;
}