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
    string s;
    cin >>n;
    long long ans = 0;
    unordered_map<string, long long> mp;
    while(n--){
        cin >>s;
        sort(s.begin(), s.end());
        ans += mp[s];
        mp[s]++;
    }
    cout <<ans;
    return 0;
}
