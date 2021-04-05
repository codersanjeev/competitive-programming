/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x;
    cin >>n >>x;
    vector<int> l(n);
    for(int i = 0; i < n; i++)
        cin >>l[i];
    vector<int> d;
    d.push_back(0);
    for(int i = 1; i <= n; i++)
        d.push_back(d[i-1] + l[i-1]);
    int i = 0, ans = 0;
    while(i <= n && d[i] <= x){
        ans++;
        i++;
    }
    cout <<ans;
    return 0;
}
