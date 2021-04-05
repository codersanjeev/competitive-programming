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
    const int mod = 2019;
    int l, r;
    cin >>l >>r;
    if((l-1) / mod != r / mod){
        cout <<0;
        return 0;
    }
    l %= mod;
    r %= mod;
    int ans = mod - 1;
    for(int i = l; i < r; i++){
        for(int j = i+1; j <= r; j++){
            ans = min(ans, (i*j)%mod);
        }
    }
    cout <<ans;
    return 0;
}
