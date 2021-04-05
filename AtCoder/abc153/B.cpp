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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int h, n, ele;
    cin >>h >>n;
    int x = 0;
    for(int i = 0; i < n; i++){
    	cin >>ele;
    	x += ele;
    }
    if(x >= h)
    	cout <<"Yes";
   	else 
   		cout <<"No";
    return 0;
}
