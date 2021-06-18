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

void solve(int tc) {
    int a, b, c, ele, ans = 0;
    cin >> a >> b >> c;
    set<int> x, y, z;
    while (a--) {
        cin >> ele;
        x.insert(ele);
    }
    while (b--) {
        cin >> ele;
        y.insert(ele);
    }
    while (c--) {
        cin >> ele;
        z.insert(ele);
    }
    vector<int> X(x.begin(), x.end()), Y(y.begin(), y.end()), Z(z.begin(), z.end());
    int i = 0, j = 0, k = 0;
    while (j < (int)Y.size()) {
        while (i < (int)X.size() && X[i] <= Y[j]) i++;
        while (k < (int)Z.size() && Z[k] <= Y[j]) k++;
        ans += (i * k);
        j++;
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; curr++) solve(curr);
    return 0;
}