#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define mod 1000000007

const double PI = 2 * acos(0.0);
const long long INF = 1e18L + 5;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
inline istream &operator>>(istream &in, vector<T> &a)
{
    for (auto &x : a)
        in >> x;
    return in;
}

template <typename T>
inline ostream &operator<<(ostream &out, vector<T> &a)
{
    for (auto &x : a)
        out << x << " ";
    return out;
}

void solve()
{
    int n, a, b;
    cin >> n;
    vector<pair<int, bool>> arr;
    while (n--)
    {
        cin >> a >> b;
        arr.push_back({a, true});
        arr.push_back({b, false});
    }
    sort(arr.begin(), arr.end());
    int ans = 0, curr = 0;
    for (const auto &ele : arr)
    {
        curr += (ele.second ? 1 : -1);
        ans = max(ans, curr);
    }
    cout << ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    solve();
    return 0;
}
