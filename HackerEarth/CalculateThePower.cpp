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
    long a, b;
    long mod = 1000000007;
    cin >>a >>b;
    long ans = 1;
    while(b > 0){
        if(b&1)
            ans = (ans * a) % mod;
        b = b >> 1;
        a = (a * a) % mod;
    }
    cout <<ans;
    return 0;
}