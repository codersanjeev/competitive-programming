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
    int t, n;
    cin >>t;
    while(t--){
    	cin >>n;
    	vector<int> arr(n);
    	for(int i = 0; i < n; i++)
    		cin >>arr[i];
    	set<int> s(arr.begin(), arr.end());
    	if(s.size() == n)
    		cout <<"No\n";
    	else
    		cout <<"Yes\n";
    }
    return 0;
}