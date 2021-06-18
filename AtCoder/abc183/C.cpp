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
    int N, K;
    read(N, K);
    vector<vector<int>> T(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            read(T[i][j]);
        }
    }
    vector<int> ans(N);
    int cnt = 0;
    for (int i = 0; i < N; i++) ans[i] = i;
    do {
        if (ans[0] == 0) {
            int curr = 0;
            for (int i = 1; i < N; i++) {
                curr += T[ans[i - 1]][ans[i]];
            }
            curr += T[ans.back()][0];
            if (curr == K) cnt++;
        }
    } while (next_permutation(ans.begin(), ans.end()));
    write(cnt);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; curr++) solve(curr);
    return 0;
}