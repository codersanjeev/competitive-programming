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
	int t, n, b, w, h, p;
	cin >>t;
	while(t--){
		cin >>n >>b;
		int ans = INT_MIN;
		for(int i = 0; i < n; i++){
			cin >>w >>h >>p;
			if(p <= b)
				ans = max(ans, (w*h));
		}
		if(ans == INT_MIN)
			cout <<"no tablet\n";
		else
			cout <<ans <<"\n";
	}
    return 0;
}