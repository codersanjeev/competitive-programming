/**
 * Template for Contests
 *
 *  @author Sanjeev
 */
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >>t;
    while(t--){
        string s;
        cin >>s;
        map<char, int> freq;
        for(int i = 0; i < s.size(); i++)
            freq[s[i]]++;
        int ans = INT_MAX;
        ans = min(ans, freq['r']);
        ans = min(ans, freq['u']);
        ans = min(ans, freq['b']);
        ans = min(ans, freq['y']);
        cout <<ans <<"\n";   
    }    
	return 0;
}