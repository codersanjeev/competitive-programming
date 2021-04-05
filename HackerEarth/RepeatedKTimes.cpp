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
    int n, ele, k;
    map<int, int> mp;
    cin >>n;
    for(int i = 0; i < n; i++){
        cin >>ele;
        mp[ele]++;
    }
    cin >>k;
    for(auto ele : mp){
        if(ele.second == k){
            cout <<ele.first;
            break;
        }
    }
    return 0;
}