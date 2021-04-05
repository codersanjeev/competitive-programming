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
    string a = s.substr(0, 2);
    string b = s.substr(2, 2);
    int x = stoi(a);
    int y = stoi(b);
    if(x >= 1 && x <= 12 && y >= 1 && y <= 12)
        cout <<"AMBIGUOUS";
    else if(y >= 1 && y <= 12)
        cout <<"YYMM";
    else if(x >= 1 && x <= 12)
        cout <<"MMYY";
    else 
        cout <<"NA";
    return 0;
}
