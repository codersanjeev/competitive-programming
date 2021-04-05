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
    map<string, int> mp;
    mp["SUN"] = 0;
    mp["MON"] = 1;
    mp["TUE"] = 2;
    mp["WED"] = 3;
    mp["THU"] = 4;
    mp["FRI"] = 5;
    mp["SAT"] = 6;
    string s;
    cin >>s;
    cout <<7 - mp[s];
    return 0;
}
