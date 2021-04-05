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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int N = n / 2;
        int t1 = 4 * (N * (N + 1) * (2 * N + 1) / 6);
        int t2 = n * (n + 1) * (2 * n + 1) / 6;
        if(n&1)
            cout<<t2 - t1<<endl;
        else
            cout<<t1<<endl;
    }
    return 0;
}