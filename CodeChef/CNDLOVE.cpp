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
    int t, n, s, ele;
    cin >>t;
    while(t--){
        s = 0;
        cin >>n;
        while(n--){
            cin >>ele;
            s += ele;
        }
        if(s%2 == 0)
            cout <<"NO\n";
        else 
            cout <<"YES\n";
    }
    return 0;
}