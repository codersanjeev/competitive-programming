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
    while(t--){
        string a;
        cin >>a;
        string b = a;
        reverse(a.begin(), a.end());
        if(a == b)
            cout <<"YES\n";
        else
            cout <<"NO\n";
    }
    return 0;
}