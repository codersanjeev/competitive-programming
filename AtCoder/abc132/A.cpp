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
    map<char, int> mp;
    for(int i = 0; i < 4; i++)
        mp[s[i]]++;
    bool flag = true;
    for(auto ele : mp)
        if(ele.second != 2)
            flag = false;
    if(flag && mp.size() == 2)
        cout <<"Yes";
    else 
        cout <<"No";
    return 0;
}
