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
    int t, n, s, e;
    cin >>t;
    while(t--){
        cin >>n;
        int ans = 0;
        while(n--){
            cin >>s >>e;
            if(e-s > 5)
                ans++;
        }
        cout <<ans <<"\n";
    }
    return 0;
}