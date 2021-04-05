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
    cin >>n;
    double ans = 0.0;
    if(n%2 == 0){
        ans = 0.5;
    }
    else{
        double N = n * 1.0;
        double num = (n/2) + 1;
        ans = num / N;
    }
    cout <<fixed <<setprecision(10) <<ans;
    return 0;
}
