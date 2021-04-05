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
    vector<long long> b(n+1), a(n);
    for(long long i = 0; i < n+1; i++)
        cin >>b[i];
    for(long long i = 0; i < n; i++)
        cin >>a[i];
    long long ans = 0;
    for(long long i = 0; i < n; i++){
        // ith hero will first finish monsters in ith position
        // and then move to (i+1)th position
        long long temp = min(a[i], b[i]);
        // kill monsters at ith position
        a[i] -= temp;
        b[i] -= temp;
        ans += temp;
        // kill monsters at (i+1)th position
        temp = min(a[i], b[i+1]);
        a[i] -= temp;
        b[i+1] -= temp;
        ans += temp;
    }
    cout <<ans;
    return 0;
}
