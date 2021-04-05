/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>

#define deb(x) cout << #x << " is " << x << "\n";

using namespace std;

long long f(long long n){
	if(n == 1)
		return 1;
	if(n == 0)
		return 0;
	long long x = f(floor(n/2));
	return 1 + x + x;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long x;
    cin >>x;
    cout <<f(x);
    return 0;
}
