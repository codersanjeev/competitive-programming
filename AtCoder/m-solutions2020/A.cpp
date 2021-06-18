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
    int x;
    cin >> x;
    if (x >= 400 && x <= 599)
    {
        cout << 8;
    }
    else if (x >= 600 && x <= 799)
    {
        cout << 7;
    }
    else if (x >= 800 && x <= 999)
    {
        cout << 6;
    }
    else if (x >= 1000 && x <= 1199)
    {
        cout << 5;
    }
    else if (x >= 1200 && x <= 1399)
    {
        cout << 4;
    }
    else if (x >= 1400 && x <= 1599)
    {
        cout << 3;
    }
    else if (x >= 1600 && x <= 1799)
    {
        cout << 2;
    }
    else if (x >= 1800 && x <= 1999)
    {
        cout << 1;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
