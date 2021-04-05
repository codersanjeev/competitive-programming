/**
 *  Template for Contests
 * 
 *  @author Sanjeev
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n;
    string s;
    cin >>t;
    for(int i = 1; i <= t; i++){
        cin >>n;
        cin >>s;
        cout <<"Case #" <<i <<": ";
        for(int j = 0; j < 2*n - 2; j++){
            if(s[j] == 'E')
                cout <<"S";
            else
                cout <<"E";
        }
        cout <<"\n";
    }
    return 0;
}