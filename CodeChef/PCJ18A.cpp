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
    int t, n, x;
    cin >>t;
    while(t--){
        cin >>n >>x;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin >>arr[i];
        bool flag = false;
        for(int i = 0; i < n; i++)
            if(arr[i] >= x)
                flag = true;
        if(flag)
            cout <<"YES\n";
        else 
            cout <<"NO\n";
    }
    return 0;
}