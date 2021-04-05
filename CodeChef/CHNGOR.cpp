/**
 *  Template for Contests
 * 
 *  @author Sanjeev
 */
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n;
    cin >>t;
    while(t--){
        cin >>n;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >>arr[i];
        int ans = arr[0];
        for(int i = 1; i < n; i++)
            ans |= arr[i];
        cout <<ans <<"\n";
    }
    return 0;
}