/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
#pragma GCC target ("sse4")
#pragma comment(linker, "/stack:200000000")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define deb(x) cout << #x << " is " << x << "\n";

using namespace std;
using namespace __gnu_pbds;

const double PI = 2 * acos(0.0);
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, p;
    string s;
    cin >>n >>m;
    vector<int> arr(n, 0);
    int ans1 = 0, ans2 = 0;
    while(m--){
        cin >>p >>s;
        if(s == "WA" && arr[p-1] != INT_MAX)
            arr[p-1]--;
        else if(s == "AC" && arr[p-1] != INT_MAX){
            ans1 += arr[p-1];
            ans2++;
            arr[p-1] = INT_MAX;
        }
    }
    cout <<ans2 <<" " <<abs(ans1);
    return 0;
}
