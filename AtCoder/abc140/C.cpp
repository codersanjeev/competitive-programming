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
    vector<int> b(n-1);
    for(int i = 0; i < n-1; i++)
        cin >>b[i];
    vector<int> c(n, INT_MAX);
    c[0] = b[0];
    c[n-1] = b[n-2];
    for(int i = 1; i < n-1; i++)
        c[i] = min(b[i-1], b[i]);
    cout <<accumulate(c.begin(), c.end(), 0);
    return 0;
}
