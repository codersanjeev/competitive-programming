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
    int N;
    read(N);
    vector<int> H(N), A(N);
    readContainer(H);
    readContainer(A);
    // subsequence with increasing Hi and maximum sum of Ai => print(sum(Ai))
    // 3 1 4 2
    // 10 20 30 40
    int base = 1;
    while (base <= N) base *= 2;
    vector<int> dp(N + 1), tree(2 * base);
    for (int i = 0; i < N; i++) {
        int curr = H[i] + base;
        int best = 0;
        while (curr > 0) {
            if (curr % 2 == 1) {
                best = max(best, tree[curr - 1]);
            }
            curr /= 2;
        }
        dp[H[i]] = best + A[i];
        for (int j = base + H[i]; j >= 1; j /= 2) {
            tree[j] = max(tree[j], dp[H[i]]);
        }
    }
    write(*max_element(dp.begin(), dp.end()));
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