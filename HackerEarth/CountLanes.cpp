#include <bits/stdc++.h>
using namespace std;

long long countLanes(long long n){
    if (n == 0) 
        return 0;
    else
        return (n & 1) + countLanes(n >> 1); 
    
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long t, n;
	cin >>t;
	while(t--){
	    cin >>n;
	    long long lanes = countLanes(n);
	    cout <<pow(2, lanes) <<endl;
	}
    return 0;
}