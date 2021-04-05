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
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin >>arr[i];
        sort(arr.begin(), arr.end());
        int ans = INT_MAX;
        for(int i = 1; i < n; i++)
            ans = min(ans, arr[i]-arr[i-1]);
        cout <<ans <<"\n";
    }
    return 0;
}