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

int upperBound(vector<int> &arr, int x) {
    int lo = -1, hi = arr.size();
    while (hi - lo > 1) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] < x)
            lo = mid;
        else
            hi = mid;
    }
    return hi;
}

int lowerBound(vector<int> &arr, int x) {
    int lo = -1, hi = arr.size();
    while (hi - lo > 1) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] <= x)
            lo = mid;
        else
            hi = mid;
    }
    return lo;
}

void solve() {
    int n, q, l, r;
    cin >> n;
    vector<int> arr(n);
    for (auto &ele : arr)
        cin >> ele;
    sort(arr.begin(), arr.end());
    cin >> q;
    while (q--) {
        cin >> l >> r;
        int lo = upperBound(arr, l);
        int hi = lowerBound(arr, r);
        // deb(lo);
        // deb(hi);
        if (lo > hi)
            cout << 0 << " ";
        else
            cout << hi - lo + 1 << " ";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
