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
    long long w, h, x, y;
    cin >>w >>h >>x >>y;
    bool flag = (x+x == w) && (y+y == h);
    cout <<fixed <<setprecision(6) <<(double(w)*double(h))/2 <<" " <<flag;
    return 0;
}
