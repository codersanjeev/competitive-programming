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
using namespace __gnu_pbds;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int n;
    cin >>n;
    // max possible answer can be n - 1 if a and b are 1 and n - 1
    long long int ans = n - 1;
    for(long long int i = 1; i <= 1000000; i++){
        if(n%i == 0){
            ans = min(ans, i + n / i - 2);
        }
    }
    cout <<ans;    
    return 0;
}
