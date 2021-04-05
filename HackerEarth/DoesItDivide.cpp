/**
 * Template for Contests
 *
 *  @author Sanjeev
 */
#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long n){
    if(n < 4)
        return true;
    for(long long i = 2; i*i <= n; i++)
        if(n%i == 0)
            return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long t, n;
    cin >>t;
    while(t--){
        cin >>n;
        if(isPrime(n+1) && n != 2)
            cout <<"YES\n";
        else
            cout <<"NO\n";
    }
    return 0;
}