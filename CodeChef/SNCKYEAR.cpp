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
    int t, n;
    cin >>t;
    while(t--){
        cin >>n;
        if(n == 2010 || n == 2015 || n == 2016 || n == 2017 || n == 2019)
            cout <<"HOSTED\n";
        else 
            cout <<"NOT HOSTED\n";
    }
    return 0;
}