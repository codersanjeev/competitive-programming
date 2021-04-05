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
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >>arr[i];
    int start = 0, ans = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] > arr[i-1])
            // we can move forward
            start = i;
        // keep on updating the maximum number of moves till ith index
        ans = max(ans, i - start);
    }
    cout <<ans;
    return 0;
}
