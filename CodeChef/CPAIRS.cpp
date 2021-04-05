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
    	int arr[n];
    	int odd[n] = {0};
    	for(int i = 0; i < n; i++){
    		cin >>arr[i];
    		if(arr[i] % 2 == 1)
    			odd[0]++;
    	}
    	for(int i = 1; i < n; i++){
    		if(arr[i-1] % 2 == 1)
    			odd[i] = odd[i-1] - 1;
    		else
    			odd[i] = odd[i-1];
    	}
    	int count = 0;
    	for(int i = 0; i < n; i++)
    		if(arr[i] % 2 == 0)
    			count += odd[i];
    	cout <<count <<"\n";
    }
    return 0;
}