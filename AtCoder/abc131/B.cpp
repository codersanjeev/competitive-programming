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
    int n, l;
    cin >>n >>l;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        arr[i] = l + i;
    int sum = accumulate(arr.begin(), arr.end(), 0);
    int ans, mn = INT_MAX;
    for(int i = 0; i < n; i++){
        int curr = 0;
        for(int j = 0; j < n; j++){
            if(i != j){
                curr += arr[j];
            }
        }
        if(abs(sum - curr) < mn){
            mn = abs(sum - curr);
            ans = curr;
        }
    }
    cout <<ans;
    return 0;
}
