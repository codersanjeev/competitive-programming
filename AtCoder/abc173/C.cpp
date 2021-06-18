#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("trapv")
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

void solve()
{
    int h, w, k;
    cin >> h >> w >> k;
    vector<vector<char>> arr(h, vector<char>(w));
    for (auto &row : arr)
    {
        for (auto &ele : row)
            cin >> ele;
    }
    int ans = 0;
    for (int maskH = 0; maskH < (1LL << h); maskH++)
    {
        for (int maskW = 0; maskW < (1LL << w); maskW++)
        {
            int curr = 0;
            for (int i = 0; i < h; i++)
            {
                for (int j = 0; j < w; j++)
                {
                    if (((maskH & (1LL << i)) == 0) && ((maskW & (1LL << j)) == 0) && arr[i][j] == '#')
                    {
                        curr++;
                    }
                }
            }
            if (curr == k)
            {
                ans++;
            }
        }
    }
    cout << ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
