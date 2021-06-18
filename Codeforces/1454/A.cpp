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
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    if (n % 2 == 0) {
        for (int i = 1; i < n; i += 2) {
            swap(arr[i], arr[i - 1]);
        }
    } else {
        for (int i = 1; i < n - 3; i += 2) {
            swap(arr[i], arr[i - 1]);
        }
        arr[n - 3] = n - 1;
        arr[n - 2] = n;
        arr[n - 1] = n - 2;
    }
    for (const auto &ele : arr) {
        write(ele, " ");
    }
    write("\n");
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