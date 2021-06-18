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

vector<int> primeFactors(int n) {
    vector<int> ans;
    int idx = 0, p = 2;
    while (p * p <= n) {
        while (n % p == 0) {
            n /= p;
            ans.push_back(p);
        }
        p++;
    }
    if (n != 1) {
        ans.push_back(n);
    }
    return ans;
}

void solve(int tc) {
    int n;
    read(n);
    vector<int> factors = primeFactors(n);
    map<int, int> mp;
    for (const auto &ele : factors) mp[ele]++;
    vector<pair<int, int>> temp;
    for (const auto &ele : mp) temp.push_back({ele.second, ele.first});
    sort(temp.begin(), temp.end(), greater<pair<int, int>>());
    vector<int> ans(temp[0].first, temp[0].second);
    write(temp[0].first, "\n");
    int x = n / pow(temp[0].second, temp[0].first);
    ans.back() *= x;
    for (const auto &ele : ans) write(ele, " ");
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