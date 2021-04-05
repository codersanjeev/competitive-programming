#include<bits/stdc++.h>
using namespace std;

/**
N Q
A1...An
q queries
*/

int compare (const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}

int main(){
	int n, q, ele;
	cin >>n >>q;
	int arr[n];
	for(int i=0; i<n; i++)
		cin >>arr[i];
	qsort(arr, n, sizeof(int), compare);
	while(q--){
		cin >>ele;
		if(binary_search(arr, arr+n, ele)){
			cout <<"YES" <<endl;
		}
		else{
			cout <<"NO" <<endl;
		}
	}
	return 0;
}