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
    string s;
    cin >>t;
    while(t--){
        cin >>s;
        string u = s;
        reverse(s.begin(), s.end());
        if(s == u)
            cout <<"YES\n";
        else
            cout <<"NO\n";
    }
    return 0;
}