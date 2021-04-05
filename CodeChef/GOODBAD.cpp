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
    int t, n, k;
    string s;
    cin >>t;
    while(t--){
        int small = 0, capital = 0;
        cin >>n >>k;
        cin >>s;
        for(int i = 0; i < n; i++){
            if(s[i] >= 'a' && s[i] <= 'z')
                small++;
            else
                capital++;
        }
        if(small <= k && capital <= k){
            cout <<"both\n";
            continue;
        }
        else if(small <= k){
            cout <<"brother\n";
            continue;
        }
        else if(capital <= k){
            cout <<"chef\n";
            continue;
        }
        else{
            cout <<"none\n";
            continue;
        }
    }
    return 0;
}