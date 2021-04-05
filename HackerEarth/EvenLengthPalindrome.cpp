#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >>t;
    while(t--){
        map<char, int> mp = {{'0', 0}, {'1', 0}, {'2', 0}, {'3', 0}, 
        {'4', 0}, {'5', 0}, {'6', 0}, {'7', 0}, {'8', 0}, {'9', 0}};
    string s;
    cin >>s;
    for(int i=0; i<s.size(); i++){
        mp[s[i]] += 2;
    }
    int ans = INT_MIN;
    char ch;
    for(auto iter = mp.rbegin(); iter != mp.rend(); ++iter){
        // iter->first
        // iter->second
        if(iter->second >= ans){
            ch = iter->first;
            ans = iter->second;
        }
    }
    cout <<ch <<"\n";
    }
    return 0;
}