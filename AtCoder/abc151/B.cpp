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

long f(long a, long b){
    if(a > b)
        return a;
    else 
        return b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long n, k, m;
    cin >>n >>k >>m;
    vector<long> arr(n-1);
    for(long i = 0; i < n - 1; i++)
        cin >>arr[i];
    long s = accumulate(arr.begin(), arr.end(), 0);
    if (s + k >= n * m) {
        cout << f(0, n*m - s) << endl;;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
