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
    int k, x;
    cin >>k >>x;
    vector<int> ans;
    int low = x - 1;
    int high = x + 1;
    ans.push_back(x);
    int temp = k - 1;
    while(low >= -1000000 && temp--){
        ans.push_back(low);
        low--;
    }
    temp = k - 1;
    while(high <= 1000000 && temp--){
        ans.push_back(high);
        high++;
    }
    sort(ans.begin(), ans.end());
    for(auto ele : ans)
        cout <<ele <<" ";
    return 0;
}
