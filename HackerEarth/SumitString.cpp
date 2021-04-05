/**
 * Template for Contests
 *
 *  @author Sanjeev
 */
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >>t;
    string s;
    while(t--){
        cin >>s;
        bool flag = true;
        for(int i = 0; i < s.size() - 1; i++){
            // cout <<abs(s[i] - s[i+1]) <<"\n";
            if(abs(s[i] - s[i+1]) != 1 && abs(s[i] - s[i+1]) != 25){
                flag = false;
            }
        }
        if(flag)
            cout <<"YES\n";
        else
            cout <<"NO\n";
    }
    return 0;
}