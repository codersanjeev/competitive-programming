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

long long MAX = 1e9;

long long findCost(long long n, long long a, long long b){
    string s = to_string(n);
    long long sz = s.size();
    return n * a + b * sz;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, x;
    cin >>a >>b >>x;
    long long cost = findCost(MAX, a, b);
    if(cost <= x){
        cout <<MAX;
        return 0;
    }
    long long lo = 0, hi = MAX, ans = -1;
    while(lo <= hi){
        long long mid = lo + (hi - lo) / 2;
        cost = findCost(mid, a, b);
        if(cost <= x){
            ans = mid;
            lo = mid + 1;
        }
        else 
            hi = mid - 1;
    }
    if(ans == -1)
        ans = 0;
    cout <<ans;
    return 0;
}
