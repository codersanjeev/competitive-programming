#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n;
	// build prime numbers sieve
	bool isPrime[100001];
	memset(isPrime, true, sizeof(isPrime));
	for(int i = 2; i*i <= 100000; i++){
		if(isPrime[i]){
			for(int j = i*i; j <= 100000; j += i)
				isPrime[j] = false;
		}
	}
	cin >>t;
	while(t--){
		cin >>n;
		if(isPrime[n])
			cout <<"yes\n";
		else
			cout <<"no\n";
	}
	return 0;
}