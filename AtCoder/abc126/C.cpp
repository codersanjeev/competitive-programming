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
    int n, k;
    cin >>n >>k;
    double ans = 0;
    for(int i = 1; i <= n; i++){
        double temp = 1.0 / n;
        int now = i;
        while(now < k){
            now *= 2;
            temp /= 2;
        }
        ans += temp;
    }
    cout <<fixed <<setprecision(12) <<ans;
    return 0;
}
