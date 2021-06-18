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

int f(int n) {
    return (n % 2 == 0 ? n / 2 : 3 * n + 1);
}

void solve(int tc) {
    int s;
    read(s);
    vector<int> arr;
    arr.push_back(s);
    unordered_map<int, int> mp;
    mp[s] = 1;
    for (int i = 2; i <= 10000; i++) {
        int curr = arr.back();
        int next = f(curr);
        if (mp[next] > 0) {
            write(i);
            break;
        }
        mp[next] = i;
        arr.push_back(next);
    }
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