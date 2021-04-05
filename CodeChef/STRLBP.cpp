/**
 *  Template for Contests
 * 
 *  @author Sanjeev
 */
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    string s;
    cin >>t;
    while(t--){
        cin >>s;
        int ans = 0;
        int n = s.size();
        for(int i = 0; i < n-1; i++){
            if(s[i] != s[i+1])
                ans++;
        }
        if(s[n-1] != s[0])
            ans++;
        if(ans <= 2)
            cout <<"uniform\n";
        else
            cout <<"non-uniform\n";
    }
    return 0;
}