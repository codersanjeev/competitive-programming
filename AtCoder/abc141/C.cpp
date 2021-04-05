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
    int ele, n, k, q;
    cin >>n >>k >>q;
    vector<int> arr(n, k - q);
    while(q--){
        cin >>ele;
        arr[ele-1]++;
    }
    for(auto x : arr)
        if(x > 0)
            cout <<"Yes\n";
        else 
            cout <<"No\n";
    return 0;
}
