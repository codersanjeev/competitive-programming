/**
 * Template for Contests
 *
 *  @author Sanjeev
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n, m;
    cin >>t;
    while(t--){
        cin >>n >>m;
        if(n%2 == 1 && m%2 == 1)
            cout <<"NO\n";
        else 
            cout <<"YES\n";
    }
    return 0;
}