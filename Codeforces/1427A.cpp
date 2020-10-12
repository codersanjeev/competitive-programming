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
int nCr(int n, int r)
{
    long double res = 1;
    r = min(r, n - r);
    for (int i = 1; i <= r; i++)
    {
        res = res * (n - r + i) / i;
    }
    return (int)(res + 0.01);
}

// (x ^ y) % mod
int modpow(int x, int y, int m)
{
    x %= m;
    int res = 1LL;
    while (y > 0)
    {
        if (y & 1)
        {
            res = (res * x) % m;
        }
        x = (x * x) % m;
        y >>= 1;
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &ele : arr)
        cin >> ele;
    int ans = accumulate(arr.begin(), arr.end(), 0LL);
    if (ans == 0)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    if (ans > 0)
    {
        sort(arr.begin(), arr.end(), greater<int>());
    }
    else
    {
        sort(arr.begin(), arr.end());
    }
    for (const auto &ele : arr)
    {
        cout << ele << " ";
    }
    cout << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}