/**
 * Template for Contests
 *
 *  @author Sanjeev
 */
#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;

long long solve(long long n, long long k){
    long long ans = 1;
    for(long long i = 0; i < n; i++)
        ans = (ans * (k-i)) % mod;
    return ans % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long t, n, k;
    cin >>t;
    while(t--){
        cin >>n >>k;
        cout <<solve(n, k) <<"\n";
    }
    return 0;
}