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
    long long n, k, ele;
    cin >>n >>k;
    priority_queue<long long> pq;
    for(long long i = 0; i < n; i++){
    	cin >>ele;
    	pq.push(ele);
    }
    long long ans = 0;
    while(!pq.empty() && k > 0){
    	pq.pop();
    	k--;
    }
    if(pq.empty())
    	cout <<ans;
   	else{
   		while(!pq.empty()){
   			ans += pq.top();
   			pq.pop();
   		}
   		cout <<ans;
   	}
    return 0;
}
