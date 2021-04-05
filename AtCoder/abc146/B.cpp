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
    int n;
    string s;
    cin >>n >>s;
    int sz = s.size();
    for(int i = 0; i < sz; i++){
        if(char(s[i] + n) > 'Z'){
            cout <<(char)(((int)s[i] + n) % (int)'Z' + 'A' - 1);
        }
        else
            cout <<char(s[i] + n);
    }
    return 0;
}
