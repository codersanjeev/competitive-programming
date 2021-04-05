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
        reverse(u.begin(), u.end());
        if(s == u){
            if(s.size()%2 == 0)
                cout <<"YES EVEN\n";
            else
                cout <<"YES ODD\n";
        }
        else{
            cout <<"NO\n";
        }
    }
    return 0;
}