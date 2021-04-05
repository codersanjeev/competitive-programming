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
    int t, x, y;
    cin >>t;
    while(t--){
        cin >>x >>y;
        while(x != 0 && y != 0){
            if(x > y)
                x %= y;
            else 
                y %= x;
        }
        cout <<2 * (x + y) <<"\n";
    }
    return 0;
}