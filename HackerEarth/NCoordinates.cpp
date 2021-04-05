/**
 *  Template for Contests
 * 
 *  @author Sanjeev
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x, y;
    cin >>n;
    map<pair<int, int>, int> mp;
    for(int i = 0; i < n; i++){
        cin >>x >>y;
        mp[make_pair(x, y)]++;
    }
    for(auto ele : mp)
        cout <<ele.first.first <<" " <<ele.first.second <<" " <<ele.second <<"\n";
    return 0;
}