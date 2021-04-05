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

const int mod = 1000000007;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, x;
    cin >>n >>m;
    // usable stairs...
    vector<bool> stairs(n+1, true);
    for(int i = 0; i < m; i++){
        cin >>x;
        // this stair is not usable
        stairs[x] = false;
    }
    vector<long long> dp(n+1);
    // base case
    dp[0] = 1;
    for(int now = 0; now < n; now++){
        for(int next = now + 1; next <= min(n, now + 2); next++){
            if(stairs[next]){
                dp[next] += dp[now];
                dp[next] %= mod;
            }
        }
    }
    cout <<dp[n] <<"\n";
    return 0;
}
