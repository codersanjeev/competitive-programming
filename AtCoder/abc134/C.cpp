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
    vector<int> temp = arr;
    sort(temp.begin(), temp.end());
    int mx = temp[n-1];
    int mx2 = temp[n-2];
    for(auto ele : arr){
        if(ele == mx)
            cout <<mx2 <<"\n";
        else 
            cout <<mx <<"\n";
    }
    return 0;
}
