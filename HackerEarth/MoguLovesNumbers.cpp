#include<bits/stdc++.h>
using namespace std;

#define size 1000001;
#define prime[1000001];
#define sum[1000001];

void generate(){
	for(int i=2; i*i<size; i++){
		if(prime[i] == 0){
			for(int j=i<<1; j<size; j+=i)
				prime[j] = 1;
		}
	}
	sum[0] = sum[1] = 0;
	for(int i=2; i<size; i++){
		sum[i] = prime[i] == 0;
		if(i){
			sum[i] += sum[i-1];
		}
	}
}

int main(){
	generate();
	int q, l, r;
	cin >>q;
	while(q--){
		cin >>l >>r;
		if(l > r)
			l ^= r ^= l ^= r;
		cout <<sum[r] - sum[l-1] <<endl;
	}
	return 0;
}