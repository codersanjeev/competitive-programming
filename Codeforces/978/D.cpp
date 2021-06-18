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
    vector<int> arr(n);
    readContainer(arr);
    if (n <= 2) {
        cout << 0;
        return;
    }
    int ans = LLONG_MAX;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int x = arr[0] + i;
            int y = arr[1] + j;
            int curr = abs(i) + abs(j), diff = y - x, prev = y;
            bool bad = false;
            for (int k = 2; k < n; k++) {
                int nxt = prev + diff;
                if (abs(nxt - arr[k]) > 1) {
                    bad = true;
                    break;
                }
                prev += diff;
                curr += abs(prev - arr[k]);
            }
            if (!bad) {
                ans = min(ans, curr);
            }
        }
    }
    if (ans != LLONG_MAX) {
        write(ans);
    } else {
        write("-1");
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