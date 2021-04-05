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
    string s;
    cin >>s;
    int n = s.size();
    bool flag = true;
    for(int i = 0; i < n; i += 2)
        if(s[i] == 'L')
            flag = false;
    for(int i = 1; i < n; i += 2)
        if(s[i] == 'R')
            flag = false;
    if(flag)
        cout <<"Yes";
    else 
        cout <<"No";
    return 0;
}
