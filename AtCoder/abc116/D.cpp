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
void read(T &...args) {
    ((cin >> args), ...);
}

template <typename... T>
void write(T &&...args) {
    ((cout << args), ...);
}

void solve(int tc) {
    int N, K;
    read(N, K);
    vector<pair<int, int>> arr(N);
    for (int i = 0; i < N; i++) {
        read(arr[i].first, arr[i].second);
        arr[i].first--;
    }
    sort(arr.begin(), arr.end(), [](const pair<int, int> &x, const pair<int, int> &y) {
        return x.second > y.second;
    });
    int ans = 0, cot = 0, type = 0, res = 0;
    vector<bool> vis(N, false);
    stack<int> s;
    for (int i = 0; i < N; i++) {
        if (cot < K) {
            if (!vis[arr[i].first]) {
                vis[arr[i].first] = true;
                type++;
            } else
                s.push(arr[i].second);
            res += arr[i].second;
            cot++;
            ans = max(ans, res + type * type);
        } else {
            if (s.empty()) break;
            if (vis[arr[i].first]) continue;
            vis[arr[i].first] = true;
            type++;
            res += arr[i].second;
            res -= s.top();
            s.pop();
            ans = max(ans, res + type * type);
        }
    }
    write(ans);
}

int32_t main() {
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