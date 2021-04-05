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
    vector<double> arr(n);
    for(int i = 0; i < n; i++)
        cin >>arr[i];
    double den = 0.0;
    for(auto ele : arr)
        if(ele != 0)
            den += (1.0 / ele);
    cout <<(1.0 / den);
    return 0;
}
