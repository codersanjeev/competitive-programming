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
		int sum = 0, max = 0;
		for(int i = 0; i <= n - k; i++){
			for(int j = i; j <= k + i - 1; j++)
				sum += arr[j];
			if(sum > max)
				max = sum;
			sum=0;         
		}
		cout <<max <<"\n";        
	}
    return 0;
}