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
    int t;
    string s;
    cin >>t;
    map<string, int> mp;
    while(t--){
        cin >>s;
        mp[s]++;
    }
    for(auto ele : mp){
        cout <<ele.first <<" " <<ele.second <<"\n";
    }
    return 0;
}