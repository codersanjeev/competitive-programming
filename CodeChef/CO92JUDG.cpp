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
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++)
            cin >>a[i];
        for(int i = 0; i < n; i++)
            cin >>b[i];
        auto it1 = max_element(a.begin(), a.end());
        auto it2 = max_element(b.begin(), b.end());
        int alice = accumulate(a.begin(), a.end(), 0) - *it1;
        int bob = accumulate(b.begin(), b.end(), 0) - *it2;
        if(alice > bob)
            cout <<"Bob\n";
        else if(alice < bob)
            cout <<"Alice\n";
        else
            cout <<"Draw\n";
    }
    return 0;
}