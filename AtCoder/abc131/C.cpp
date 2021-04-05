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

unsigned long long lcm(unsigned long long a, unsigned long long b){
    if(a == 0 && b == 0)
        return 0;
    return a/__gcd(a, b) * b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    unsigned long long a, b, c, d;
    cin >>a >>b >>c >>d;
    unsigned long long total = b - a + 1;
    unsigned long long lcmcd = lcm(c, d);
    cout <<total - ((b/c) - (a-1)/c) - ((b/d) - (a-1)/d) + ((b/lcmcd) - (a-1)/lcmcd);
    return 0;
}
