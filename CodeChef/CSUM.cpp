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
    int t, n, k;
    cin >>t;
    while(t--){
    	cin >>n >>k;
    	int arr[n];
    	for(int i = 0; i < n; i++)
    		cin >>arr[i];
    	sort(arr, arr + n);
    	int i = 0, j = n - 1;
    	bool flag = false;
    	while(i < j){
    		int curr = arr[i] + arr[j];
    		if(curr == k){
    			flag = true;
    			break;
    		}
    		if(curr > k)
    			j--;
    		else
    			i++;
    	}
    	if(flag)
    		cout <<"Yes\n";
    	else
    		cout <<"No\n";
    }
    return 0;
}