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
    int a, b;
    cin >>a >>b;
    int x = (a + b) / 2;
    if(a == b)
        cout <<0;
    else if((a < x && b > x && x - a == b - x) || (a > x && b < x && a - x == x - b))
        cout <<x;
    else 
        cout <<"IMPOSSIBLE";
    return 0;
}
