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
    int n;
    cin >>n;
    vector<int> a(n), b(n), c(n-1);
    for(int i = 0; i < n; i++)
        cin >>a[i];
    for(int i = 0; i < n; i++)
        cin >>b[i];
    for(int i = 0; i < n-1; i++)
        cin >>c[i];
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += b[a[i]-1];
        if(i > 0 && a[i] - a[i-1] == 1)
            ans += c[a[i-1]-1];
    }
    cout <<ans;
    return 0;
}
