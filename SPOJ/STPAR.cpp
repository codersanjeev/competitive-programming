/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
#pragma GCC target("sse4")
#pragma comment(linker, "/stack:200000000")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define deb(x) cout << #x << " is " << x << "\n";
#define int long long
#define mod 1000000007

const double PI = 2 * acos(0.0);
const long long INF = 1e18L + 5;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

bool check(vector<int> &order) {
    stack<int> st;
    int need = 1;
    bool ans = true;
    for (auto ele : order) {
        while (!st.empty() && st.top() == need) {
            need++;
            st.pop();
        }
        if (ele == need) {
            need++;
        } else if (!st.empty() && st.top() < ele) {
            ans = false;
            break;
        } else {
            st.push(ele);
        }
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    while (1) {
        cin >> n;
        if (n == 0)
            break;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << (check(arr) ? "yes\n" : "no\n");
    }
    return 0;
}
