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

const int M = 2e5 + 5;
vector<int> ARR(M, 0);

void solve(int tc) {
    int N, W, Si, Ti, Pi;
    read(N, W);
    while (N--) {
        read(Si, Ti, Pi);
        ARR[Si] += Pi;
        ARR[Ti] -= Pi;
    }
    for (int i = 1; i < M; i++) ARR[i] += ARR[i - 1];
    bool flag = true;
    for (const auto &ele : ARR) {
        if (ele > W) {
            flag = false;
            break;
        }
    }
    if (flag) {
        write("Yes\n");
    } else {
        write("No\n");
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; curr++) solve(curr);
    return 0;
}