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

vector<int> fact(9, 1);

int findRank(vector<int> &arr){
    if(arr.size() < 2)
        return 1;
    int n = arr.size();
    int ans = 0;
    for(int i = 0; i < n - 1; i++){
        int g = 0;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[i])
                g++;
        }
        ans += (g * fact[n - i - 1]);
    }
    return ans + 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i = 2; i <= 8; i++) 
        fact[i] = i * fact[i-1];
    int n;
    cin >>n;
    vector<int> p(n), q(n);
    for(int i = 0; i < n; i++)
        cin >>p[i];
    for(int i = 0; i < n; i++)
        cin >>q[i];
    int a = findRank(p);
    int b = findRank(q);
    cout <<abs(a - b);
    return 0;
}