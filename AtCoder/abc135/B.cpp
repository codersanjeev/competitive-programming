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
    if(is_sorted(arr.begin(), arr.end())){
        cout <<"YES";
        return 0;
    }
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++){
        if(arr[i] != i + 1){
            mp[i + 1] = arr[i];
        }
    }
    if(mp.size() != 2)
        cout <<"NO";
    else 
        cout <<"YES";
    return 0;
}
