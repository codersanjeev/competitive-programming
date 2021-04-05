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
    long long n;
    cin >>n;
    vector<long long> arr(n);
    for(long long i = 0; i < n; i++)
        cin >>arr[i];
    long long mx = 0;
    for(long long i = 0; i < n; i++){
        mx = max(mx, arr[i]);
        if(abs(mx - arr[i]) >= 2){
            cout <<"No";
            return 0;
        }
    }
    cout <<"Yes";
    return 0;
}
