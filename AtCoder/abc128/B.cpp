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
    int n, p;
    string s;
    cin >>n;
    vector<pair<pair<string, int>, int>> arr(n);
    for(int i = 0; i < n; i++){
        cin >>s >>p;
        arr[i] = {{s, -p}, i+1};
    }
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++)
        cout <<arr[i].second <<"\n";
    return 0;
}
