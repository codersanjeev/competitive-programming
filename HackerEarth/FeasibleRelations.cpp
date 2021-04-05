#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("trapv")
#pragma GCC target("sse4")

#include <bits/stdc++.h>

using namespace std;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define mod 1000000007
#define PI acos(-1)

// C(n, r) = n! / (r! * (n - r)!)
// C(n, r) = C(n, n - r)
// C(n, r) = C(n - 1, r - 1) + C(n - 1, r)
int nCr(int n, int r) {
    long double res = 1;
    r = min(r, n - r);
    for (int i = 1; i <= r; i++) {
        res = res * (n - r + i) / i;
    }
    return (int) (res + 0.01);
}

// (x ^ y) % mod
int modpow(int x, int y, int m) {
    x %= m;
    int res = 1LL;
    while (y > 0) {
        if (y & 1) {
            res = (res * x) % m;
        }
        x = (x * x) % m;
        y >>= 1;
    }
    return res;
}

int findParent(vector<int> &par, int u) {
    while(u != par[u]) {
        u = par[u];
    }
    return u;
}

void unionTree(vector<int> &par, vector<int> &rank, int u, int v) {
    int a = findParent(par, u);
    int b = findParent(par, v);
    if(a != b) {
        if(rank[a] > rank[b]) {
            par[b] = a;
            rank[a] += rank[b];
        } else {
            par[a] = b;
            rank[b] += rank[a];
        }
    }
}

void solve() {
    int N, K, x1, x2;
    string r;
    cin >> N >> K;
    vector<pair<int, int>> notequal;
    vector<int> par(N, 0);
    vector<int> rank(N, 1);
    for(int i = 0; i < N; i++) {
        par[i] = i;
        rank[i] = 1;
    }
    while(K--) {
        cin >> x1 >> r >> x2;
        x1--;
        x2--;
        if(r == "=") {
            if(x1 != x2) {
                unionTree(par, rank, x1, x2);
            }
        } else {
            notequal.push_back({x1, x2});
        }
    }
    bool ok = true;
    for(const auto &ele : notequal) {
        int x = ele.first;
        int y = ele.second;
        int u = findParent(par, x);
        int v = findParent(par, y);
        if(u == v) {
            ok = false;
            break;
        }
    }
    cout << (ok ? "YES\n" : "NO\n");
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
