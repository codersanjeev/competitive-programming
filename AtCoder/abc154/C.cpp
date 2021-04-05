/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " is " << x << "\n";

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, ele;
    cin >>n;
	unordered_set<int> st;
    for(int i = 0; i < n; i++){
		cin >>ele;
		st.insert(ele);
	}
	if(st.size() == n){
		cout <<"YES";
	}
	else{
		cout <<"NO";
	}
	return 0;
}
