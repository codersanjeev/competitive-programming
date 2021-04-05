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
    vector<int> w(n);
    for(int i = 0; i < n; i++)
        cin >>w[i];
    vector<int> left;
    left.push_back(w[0]);
    for(int i = 1; i < n; i++)
        left.push_back(left[i-1] + w[i]);
    int total = accumulate(w.begin(), w.end(), 0);
    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
        int s1 = left[i];
        int s2 = total - s1;
        ans = min(ans, abs(s2-s1));
    }
    cout <<ans;
    return 0;
}
